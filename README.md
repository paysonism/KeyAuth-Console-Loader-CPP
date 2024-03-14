# Payson's KeyAuth Loader

This is a really simple keyauth loader that I made in class. It is written in c++. This may be useful if you want a clean c++ application with a login system. KeyAuth is already included in the code and all you have to do is fill out your KeyAuth App info at the top of ConsoleLoader.cpp

## How to use

The first thing we need to do to be able to use this loader is to add your keyauth information. At the top of the ConsoleLoader.cpp you will see some code that looks like this:

```cpp
auto name = skCrypt("payson1337");
auto ownerid = skCrypt("CFGB975qwf");
auto secret = skCrypt("4ceea7f8f25d6da3772B5b25a621c346f7a76870e8d7794f469aa74df673684d");
auto version = skCrypt("1.0");
auto url = skCrypt("https://keyauth.win/api/1.2/"); // change if you're self-hosting
```
You are gonna want to fill it out just like I did above. You can find this information inside of the [Manage Applications](https://keyauth.cc/app/?page=manage-apps) page in keyauth.

Now the loader should be fully working and you are able to login and test its features out!

## More to come

I plan on making this loader really good or having other loader's that I make on my github. I might make a few with some ImGui's and post them I don't really know. If you liked this loader please star the repo.

# Important Links

<em><strong>KeyAuth: </strong></em> [KeyAuth Homepage](https://keyauth.cc)

<em><strong>My GitHub: </strong></em> [paysonism](https://github.com/paysonism)

# Credits

Made By [Payson](https://github.com/paysonism)
