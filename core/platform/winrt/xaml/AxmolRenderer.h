/*
* cocos2d-x   https://axmolengine.github.io/
*
* Copyright (c) 2010-2014 - cocos2d-x community
* Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
*
* Portions Copyright (c) Microsoft Open Technologies, Inc.
* All Rights Reserved
*
* Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an
* "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and limitations under the License.
*/
#pragma once

#include <agile.h>
#include "platform/winrt/InputEvent.h"
#include "base/Types.h"

class AppDelegate;

class AxmolRenderer
{
public:
    AxmolRenderer(int width,
                  int height,
                  float dpi, 
        Windows::Graphics::Display::DisplayOrientations orientation, 
        Windows::UI::Core::CoreDispatcher^ dispatcher, Windows::UI::Xaml::Controls::Panel^ panel);
    AxmolRenderer(const AxmolRenderer&) = delete;
    ~AxmolRenderer();
    void SetQueueOperationCb(std::function<void(ax::AsyncOperation, void*)> op);
    void Draw(size_t width, size_t height, float dpi, Windows::Graphics::Display::DisplayOrientations orientation);
	void QueuePointerEvent(ax::PointerEventType type, Windows::UI::Core::PointerEventArgs^ args);
    void QueueKeyboardEvent(ax::WinRTKeyboardEventType type, Windows::UI::Core::KeyEventArgs ^ args);
	void QueueBackButtonEvent();
    void Pause();
    void Resume();
    void DeviceLost();
    bool AppShouldExit();

private:

    int m_width;
    int m_height;
    float m_dpi;

    Platform::Agile<Windows::UI::Core::CoreDispatcher> m_dispatcher;
    Platform::Agile<Windows::UI::Xaml::Controls::Panel> m_panel;
    Windows::Graphics::Display::DisplayOrientations m_orientation;
};
