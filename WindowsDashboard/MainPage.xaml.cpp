//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace WindowsDashboard;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

ref struct EventHelper
{
	static void OnBtnClick(Object^ sender, RoutedEventArgs^ e)
	{
		if (Windows::UI::ViewManagement::ApplicationView::GetForCurrentView()->IsFullScreenMode) {
			Windows::UI::ViewManagement::ApplicationView::GetForCurrentView()->ExitFullScreenMode();
		}
		else {
			Windows::UI::ViewManagement::ApplicationView::GetForCurrentView()->TryEnterFullScreenMode();
		}
		
	}
};

MainPage::MainPage()
{
	InitializeComponent();

	// Add button for toggling fullscreen
	AppBarButton^ switchDisplayMonitorButton = ref new AppBarButton();
	switchDisplayMonitorButton->Label = "Toggle Fullscreen";
	switchDisplayMonitorButton->Click += ref new RoutedEventHandler(&EventHelper::OnBtnClick);
	MainCommandBar->SecondaryCommands->Append(switchDisplayMonitorButton);

	// HACK: Uses last known non-fullscreen position
	//       Then triggers fullscreen, this allows us to remember
	//       Last screen that it was fullscreened in, instead of
	//       defaulting to primary screen.
	Windows::UI::ViewManagement::ApplicationView::GetForCurrentView()->TryEnterFullScreenMode();
}
