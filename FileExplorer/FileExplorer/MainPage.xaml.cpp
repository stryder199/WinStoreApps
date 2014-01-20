//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace FileExplorer;

using namespace Platform;
using namespace Platform::Collections;
using namespace concurrency;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();
}

/// <summary>
/// Populates the page with content passed during navigation.  Any saved state is also
/// provided when recreating a page from a prior session.
/// </summary>
/// <param name="sender">
/// The source of the event; typically <see cref="NavigationHelper"/>
/// </param>
/// <see cref="Frame::Navigate(Type, Object)"/> when this page was initially requested and
/// a dictionary of state preserved by this page during an earlier
/// session.  The state will be null the first time a page is visited.</param>
void MainPage::LoadState(Object^ sender, Common::LoadStateEventArgs^ e)
{
	(void) sender;	// Unused parameter
	(void) e;		// Unused parameter

	// TODO: Create an appropriate data model for your problem domain to replace the sample data
	Data::FSDataSource::GetItems()
		.then([this](IIterable<Data::FSDataItem^>^ FSitems)
	{
		DefaultViewModel->Insert("Items", FSitems);
	}, task_continuation_context::use_current());
}