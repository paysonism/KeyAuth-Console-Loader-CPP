#include <Windows.h>
#include <iostream>
#include "includes.h"
#include <filesystem>

using namespace KeyAuth;

auto name = skCrypt("");
auto ownerid = skCrypt("");
auto secret = skCrypt("");
auto version = skCrypt("1.0");
auto url = skCrypt("https://keyauth.win/api/1.2/");

api KeyAuthApp(name.decrypt(), ownerid.decrypt(), secret.decrypt(), version.decrypt(), url.decrypt());

void cheat()
{
    system("cls");
    std::cout << "Add your cheat code here, you could have it convert a file from bytes and run that file or you can add some of the launcher code from this project directly into your cheat launcher to allow for seamless execution and it will be harder to leak your loader.";
    Sleep(8000);
}

void spoof()
{
    system("cls");
    std::cout << "Add your spoof code here. This can jus be converting from bytes and then running them the same way you would with any kdmapper loader. Converting from bytes makes it harder for someone to steal your driver or mapper.";
    Sleep(5000);
}

void menu()
{
    system("cls");
    SetConsoleTitleA("Payson's Loader - github.com/paysonism");
    std::cout << "\n [1] Spoof\n [2] Load Cheat\n [3] Discord\n\n > ";
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:
        spoof();
        menu();
        break;
    case 2:
        cheat();
        menu();
        break;
    case 3:
        system("start https://discord.gg/saturniv");
        menu();
        break;
    }
}

int main()
{
    KeyAuthApp.init();
    name.clear(); ownerid.clear(); secret.clear(); version.clear(); url.clear();
    SetConsoleTitleA("Payson's Loader - github.com/paysonism");
    system("color E");
    std::cout << "\n Welcome to Payson's Loader!\n\n github.com/paysonism";
    Sleep(3000);
    system("cls");
    std::cout << "\n WARNING: Use of this product without buying a license is forbidden. Please do not share your keys with anyone.";
    Sleep(5000);
    system("cls");
    if (std::filesystem::exists("C:\\Windows\\payson")) //change test.txt to the path of your file :smile:
    {
        if (!CheckIfJsonKeyExists("C:\\Windows\\payson", "username"))
        {
            std::string key = ReadFromJson("C:\\Windows\\payson", "license");
            KeyAuthApp.license(key);
            if (!KeyAuthApp.data.success)
            {
                std::remove("C:\\Windows\\payson");
                std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
                Sleep(1500);
                exit(1);
            }
            std::cout << skCrypt("\n\n Successfully Logged In\n");
        }
        else
        {
            std::string username = ReadFromJson("C:\\Windows\\payson", "username");
            std::string password = ReadFromJson("C:\\Windows\\payson", "password");
            KeyAuthApp.login(username, password);
            if (!KeyAuthApp.data.success)
            {
                std::remove("C:\\Windows\\payson");
                std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
                Sleep(1500);
                exit(1);
            }
            std::cout << skCrypt("\n\n Successfully Logged In\n");
        }
    }
    else
    {
        std::cout << "\n Key > ";
        std::string key;
        std::cin >> key;
        KeyAuthApp.license(key);
        if (key.empty())
        {
            WriteToJson("C:\\Windows\\payson", "license", key, false, "", "");
            std::cout << skCrypt("\n Saved Key");
        }
    }

    if (KeyAuthApp.data.success)
    {
        menu();
    }

    if (!KeyAuthApp.data.success)
    {
        system("cls");
        std::cout << "\n " << KeyAuthApp.data.message;
    }
}
