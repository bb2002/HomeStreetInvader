#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include <iostream>
#include <chrono>


Scene* Scene::currentScene;
Scene* Scene::nextScene;
using namespace std::chrono;

Scene::Scene(): resourceManager(new ResourceManager())	//동적할당
{
}

Scene::~Scene()
{
	//Scene이 종료되었을 때 호출되는 소멸자
	//gameObjectList (모든 오브젝트)를 삭제
	for (auto& i : gameObjectList)
	{
		SAFE_DELETE(i);
	}

	//게임오브젝트리스트와 렌더러블리스트에 남은 포인터 변수들은
	//모두 delete된 변수이므로
	//리스트를 비워주는 clear함수로 리스트를 비워주기만 함.
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

auto GetCurrentTimeMilliSecond = []() -> long long {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
};

// 이전 틱에 대한 시간
long long BeforeTickMillisecond = GetCurrentTimeMilliSecond();

void Scene::Update()
{
	// Update.
	long long UpdateStartTime = GetCurrentTimeMilliSecond();

	for (auto& i : gameObjectList) {
		if (i->GetActive()) {
			i->Update();
			i->UpdateWithDelta((UpdateStartTime - BeforeTickMillisecond) / 1000.0F);
		}
	}

	//LateUpdate 수행
	for (auto& i : gameObjectList)
		if (i->GetActive())
			i->LateUpdate();

	// Scene 의 Delta Update 실행.

	UpdateStartTime = GetCurrentTimeMilliSecond();
	UpdateWithDeltaSecond((UpdateStartTime - BeforeTickMillisecond) / 1000.0F);

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

	BeforeTickMillisecond = GetCurrentTimeMilliSecond();
}

void Scene::UpdateWithDeltaSecond(float DeltaSec)
{
}

void Scene::Render()
{
	//싱글턴 패턴, Getter
	//d2dapp과 rendertarget을 받아옴
	D2DApp& d2dapp = Framework::GetInstance().GetD2DApp();
	ID2D1HwndRenderTarget& renderTarget = Framework::GetInstance().GetD2DApp().GetRenderTarget();

	
	d2dapp.BeginRender();//렌더 시작	
	for (auto& i : renderableList)
		i->renderer->Render(renderTarget,*i->transform);	
	d2dapp.EndRender();//렌더 종료
}

GameObject* Scene::PushBackGameObject(GameObject* gameObject)
{
	//게임 오브젝트에 집어넣음
	gameObjectList.push_back(gameObject);
	//렌더러에 이미지가 있을경우
	//렌더러블 리스트에 집어넣음
	if (gameObject->renderer->GetInitialized())
	{
		renderableList.push_back(gameObject);
	}
	return gameObject;//받은 게임오브젝트를 그대로 반환
}

void Scene::Destroy(GameObject* o)
{
	//삭제될 오브젝트 리스트에 집어넣음
	destroyedObjectList.push_back(o);
}


ResourceManager& Scene::GetResourceManager()
{
	return *resourceManager;
}
