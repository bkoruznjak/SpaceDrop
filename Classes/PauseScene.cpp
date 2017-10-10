//
// Created by Borna Koruznjak on 08/10/2017.
//

#include "PauseScene.h"

USING_NS_CC;

Scene *PauseScene::createScene() {
    return PauseScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameOverScene.cpp\n");
}

// on "init" you need to initialize your instance
bool PauseScene::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();

    auto resumeItem = MenuItemImage::create("assets/res/PauseScene/img_button_resume.png",
                                            "assets/res/PauseScene/img_button_resume_clicked.png",
                                            CC_CALLBACK_1(PauseScene::resume, this));

    auto retryItem = MenuItemImage::create("assets/res/PauseScene/img_button_retry.png",
                                           "assets/res/PauseScene/img_button_retry_clicked.png",
                                           CC_CALLBACK_1(PauseScene::retry, this));

    auto mainMenuItem = MenuItemImage::create("assets/res/PauseScene/img_button_menu.png",
                                              "assets/res/PauseScene/img_button_menu_clicked.png",
                                              CC_CALLBACK_1(PauseScene::goToMainMenuScene, this));

    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem, NULL);

    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    return true;
}

void PauseScene::goToMainMenuScene(cocos2d::Ref *pSender) {
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}


void PauseScene::resume(cocos2d::Ref *pSender) {
    Director::getInstance()->popScene();
}

void PauseScene::retry(cocos2d::Ref *pSender) {
    auto scene = GameScene::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);

}