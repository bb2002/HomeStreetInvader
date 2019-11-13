#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include <iostream>
#include <chrono>


Scene* Scene::currentScene;
Scene* Scene::nextScene;
using namespace std::chrono;

Scene::Scene(): resourceManager(new ResourceManager())	//�����Ҵ�
{
}

Scene::~Scene()
{
	//Scene�� ����Ǿ��� �� ȣ��Ǵ� �Ҹ���
	//gameObjectList (��� ������Ʈ)�� ����
	for (auto& i : gameObjectList)
	{
		SAFE_DELETE(i);
	}

	//���ӿ�����Ʈ����Ʈ�� ����������Ʈ�� ���� ������ ��������
	//��� delete�� �����̹Ƿ�
	//����Ʈ�� ����ִ� clear�Լ��� ����Ʈ�� ����ֱ⸸ ��.
	gameObjectList.clear();
	renderableList.clear();
	SAFE_DELETE(resourceManager);
}

void Scene::SwapScene()
{
	if (!nextScene)
		return;

	SAFE_DELETE(currentScene);
	currentScene = nextScene;
	nextScene = nullptr;

	currentScene->Initialize();
}

void Scene::ChangeScene(Scene* nextScene)
{
	Scene::nextScene = nextScene;
}

Scene& Scene::GetCurrentScene()
{
	return *Scene::currentScene;
}

auto CurrentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
void Scene::Update()
{
	auto Now = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	//��� ������Ʈ�� Update�� ����
	for (auto& i : gameObjectList) {
		if (i->GetActive()) {
			i->Update();
			i->UpdateWithDelta((Now - CurrentTime).count());
		}
	}

	UpdateWithDeltaSecond((Now - CurrentTime).count());
	CurrentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	//LateUpdate ����
	for (auto& i : gameObjectList)
		if (i->GetActive())
			i->LateUpdate();

	//���� ��û���� ������Ʈ�� ������.
	//for (auto i = destroyedObjectList.begin(); i != destroyedObjectList.end(); ++i)
	//{
	//	(*i)->OnDestroy();				//������ ȣ��� �Լ�

	//	gameObjectList.remove(*i);		//���ӿ�����Ʈ����Ʈ���� ����
	//	renderableList.remove(*i);		//�������� ����Ʈ���� ����
	//	SAFE_DELETE(*i);				//delete
	//}
	//destroyedObjectList.clear();
	auto i = destroyedObjectList.begin();
	while (i != destroyedObjectList.end())
	{
		(*i)->OnDestroy();
		gameObjectList.remove(*i);
		renderableList.remove(*i);
		GameObject* t = *i;
		SAFE_DELETE(t);
		destroyedObjectList.remove(*i);
		i = destroyedObjectList.begin();
	}
	destroyedObjectList.clear();
}

void Scene::UpdateWithDeltaSecond(float DeltaSec)
{
}

void Scene::Render()
{
	//�̱��� ����, Getter
	//d2dapp�� rendertarget�� �޾ƿ�
	D2DApp& d2dapp = Framework::GetInstance().GetD2DApp();
	ID2D1HwndRenderTarget& renderTarget = Framework::GetInstance().GetD2DApp().GetRenderTarget();

	
	d2dapp.BeginRender();//���� ����	
	for (auto& i : renderableList)
		i->renderer->Render(renderTarget,*i->transform);	
	d2dapp.EndRender();//���� ����
}

GameObject* Scene::PushBackGameObject(GameObject* gameObject)
{
	//���� ������Ʈ�� �������
	gameObjectList.push_back(gameObject);
	//�������� �̹����� �������
	//�������� ����Ʈ�� �������
	if (gameObject->renderer->GetInitialized())
	{
		renderableList.push_back(gameObject);
	}
	return gameObject;//���� ���ӿ�����Ʈ�� �״�� ��ȯ
}

void Scene::Destroy(GameObject* o)
{
	//������ ������Ʈ ����Ʈ�� �������
	destroyedObjectList.push_back(o);
}


ResourceManager& Scene::GetResourceManager()
{
	return *resourceManager;
}
