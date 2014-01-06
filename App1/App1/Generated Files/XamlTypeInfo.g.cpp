﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"
#include "XamlTypeInfo.g.h"

#include "App.xaml.h"
#include "GroupedItemsPage.xaml.h"
#include "GroupDetailPage.xaml.h"
#include "ItemDetailPage.xaml.h"

#include "App.g.hpp"
#include "GroupedItemsPage.g.hpp"
#include "GroupDetailPage.g.hpp"
#include "ItemDetailPage.g.hpp"

::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::OtherProviders::get()
{
    if(_otherProviders == nullptr)
    {
        _otherProviders = ref new ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>();
    }
    return _otherProviders;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForName(::Platform::String^ typeName)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(typeName);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForType(::Windows::UI::Xaml::Interop::TypeName t)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(t);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlType(::Platform::String^ typeName)
{
    if (typeName == L"Windows.UI.Xaml.Controls.Page")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Windows.UI.Xaml.Controls.UserControl")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Object")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"String")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Windows.UI.Xaml.Interop.TypeName")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"App1.GroupedItemsPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::App1::GroupedItemsPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"App1.Common.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->AddMemberName(L"GoForwardCommand");
        userType->AddMemberName(L"GoBackCommand");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"Windows.Foundation.Collections.IObservableMap`2<String, Object>")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, nullptr);
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Metadata;
        userType->DictionaryAdd =
            [](Object^ instance, Object^ key, Object^ item) -> void
            {
                auto collection = (Windows::Foundation::Collections::IObservableMap<::Platform::String^, ::Platform::Object^>^)instance;
                auto newKey = (Platform::String^)key;
                auto newItem = (Platform::Object^)item;
                collection->Insert(newKey, newItem);
            };
        userType->SetIsReturnTypeStub();
        return userType;
    }

    if (typeName == L"App1.GroupDetailPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::App1::GroupDetailPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"App1.ItemDetailPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::App1::ItemDetailPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"App1.Common.RelayCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->SetIsReturnTypeStub();
        return userType;
    }

    if (typeName == L"App1.Data.SampleDataItem")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->AddMemberName(L"Type");
        userType->AddMemberName(L"ImagePath");
        userType->AddMemberName(L"Content");
        userType->AddMemberName(L"Description");
        userType->AddMemberName(L"Subtitle");
        userType->AddMemberName(L"Title");
        userType->AddMemberName(L"UniqueId");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"App1.Data.SampleDataGroup")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->AddMemberName(L"Type");
        userType->AddMemberName(L"ImagePath");
        userType->AddMemberName(L"Items");
        userType->AddMemberName(L"Description");
        userType->AddMemberName(L"Subtitle");
        userType->AddMemberName(L"Title");
        userType->AddMemberName(L"UniqueId");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"Windows.Foundation.Collections.IObservableVector`1<App1.Data.SampleDataItem>")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, nullptr);
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Metadata;
        userType->CollectionAdd =
            [](Object^ instance, Object^ item) -> void
            {
                auto collection = (Windows::Foundation::Collections::IObservableVector<::App1::Data::SampleDataItem^>^)instance;
                auto newItem = (App1::Data::SampleDataItem^)item;
                collection->Append(newItem);
            };
        userType->SetIsReturnTypeStub();
        return userType;
    }

    if (typeName == L"App1.Data.SampleDataSource")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->AddMemberName(L"Groups");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"Windows.Foundation.Collections.IObservableVector`1<App1.Data.SampleDataGroup>")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, nullptr);
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Metadata;
        userType->CollectionAdd =
            [](Object^ instance, Object^ item) -> void
            {
                auto collection = (Windows::Foundation::Collections::IObservableVector<::App1::Data::SampleDataGroup^>^)instance;
                auto newItem = (App1::Data::SampleDataGroup^)item;
                collection->Append(newItem);
            };
        userType->SetIsReturnTypeStub();
        return userType;
    }

    return nullptr;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlMember(::Platform::String^ longMemberName)
{
    if (longMemberName == L"App1.GroupedItemsPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"App1.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::GroupedItemsPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.GroupedItemsPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::GroupedItemsPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.GroupDetailPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"App1.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::GroupDetailPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.GroupDetailPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::GroupDetailPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.ItemDetailPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"App1.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::ItemDetailPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.ItemDetailPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::ItemDetailPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Common.NavigationHelper.GoForwardCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"GoForwardCommand", L"App1.Common.RelayCommand");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Common::NavigationHelper^)instance;
                return that->GoForwardCommand;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Common.NavigationHelper.GoBackCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"GoBackCommand", L"App1.Common.RelayCommand");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Common::NavigationHelper^)instance;
                return that->GoBackCommand;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataItem.Type")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Type", L"Windows.UI.Xaml.Interop.TypeName");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataItem^)instance;
                auto value = ref new ::Platform::Box<::Windows::UI::Xaml::Interop::TypeName>(that->Type);
                return value;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataItem.ImagePath")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"ImagePath", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataItem^)instance;
                return that->ImagePath;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataItem.Content")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Content", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataItem^)instance;
                return that->Content;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataItem.Description")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Description", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataItem^)instance;
                return that->Description;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataItem.Subtitle")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Subtitle", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataItem^)instance;
                return that->Subtitle;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataItem.Title")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Title", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataItem^)instance;
                return that->Title;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataItem.UniqueId")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"UniqueId", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataItem^)instance;
                return that->UniqueId;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataGroup.Type")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Type", L"Windows.UI.Xaml.Interop.TypeName");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataGroup^)instance;
                auto value = ref new ::Platform::Box<::Windows::UI::Xaml::Interop::TypeName>(that->Type);
                return value;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataGroup.ImagePath")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"ImagePath", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataGroup^)instance;
                return that->ImagePath;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataGroup.Items")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Items", L"Windows.Foundation.Collections.IObservableVector`1<App1.Data.SampleDataItem>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataGroup^)instance;
                return that->Items;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataGroup.Description")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Description", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataGroup^)instance;
                return that->Description;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataGroup.Subtitle")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Subtitle", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataGroup^)instance;
                return that->Subtitle;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataGroup.Title")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Title", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataGroup^)instance;
                return that->Title;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataGroup.UniqueId")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"UniqueId", L"String");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataGroup^)instance;
                return that->UniqueId;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Data.SampleDataSource.Groups")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"Groups", L"Windows.Foundation.Collections.IObservableVector`1<App1.Data.SampleDataGroup>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Data::SampleDataSource^)instance;
                return that->Groups;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    return nullptr;
}

