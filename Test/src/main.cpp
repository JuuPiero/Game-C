#include "TestApp.h"

int main(int argc, char* argv[]) {
    // sức mạnh của con trỏ void quá khủng khiếp
    // void* a;
    // std::string str = "hello world";
    // a = &str;
    // std::string* str2 = (std::string*)(a);
    // PrintLn(*str2);

    auto app = TestApp::GetInstance();
    app->SetWindowProps(WindowProps("TestApp", 400 ,400));
    app->Run([]() {
        Window::ClearBackground(255, 255, 255, 255);
    });
    app->ShutDown();

    return 0;
}