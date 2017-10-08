//
// Created by Borna Koruznjak on 08/10/2017.
//

#include "GameOverScene.h"

USING_NS_CC;

Scene *GameOverScene::createScene() {
    return GameOverScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameOverScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameOverScene::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

void GameOverScene::goToGameScene(cocos2d::Ref *pSender) {
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(scene);
}

void GameOverScene::goToMainMenuScene(cocos2d::Ref *pSender) {
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(scene);
}

