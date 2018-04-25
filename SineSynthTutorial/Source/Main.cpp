/*
  ==============================================================================

    This file was auto-generated and contains the startup code for a PIP.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SineSynthTutorial_03.h"

class Application    : public JUCEApplication
{
public:
    //==============================================================================
    Application() {}

    const String getApplicationName() override       { return "SineSynthTutorial"; }
    const String getApplicationVersion() override    { return "3.0.0"; }

    void initialise (const String&) override         { mainWindow = new MainWindow ("SineSynthTutorial", new MainContentComponent()); }
    void shutdown() override                         { mainWindow = nullptr; }

private:
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (const String& name, Component* c)  : DocumentWindow (name,
                                                                         Desktop::getInstance().getDefaultLookAndFeel()
                                                                                               .findColour (ResizableWindow::backgroundColourId),
                                                                         DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (c, true);

           #if JUCE_ANDROID || JUCE_IOS
            setFullScreen (true);
           #else
            setResizable (true, false);
            setResizeLimits (300, 250, 10000, 10000);
            centreWithSize (getWidth(), getHeight());
           #endif

            setVisible (true);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };
    ScopedPointer<MainWindow> mainWindow;
};

//==============================================================================
START_JUCE_APPLICATION (Application)
