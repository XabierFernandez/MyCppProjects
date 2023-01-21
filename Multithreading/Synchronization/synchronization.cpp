#include <iostream>
#include <functional>
#include <thread>

using namespace std;

//POOR INTERFACE, BECAUSE THE USER HAS TO CHECK IF THE ARRAY IS FULL OR EMPTY BEFOREHAND
//callable object
class Messages
{
    public:
        Messages(const int& size): 
        ArraySize(size),
        currentIdx(0),
        msgArray(new string[ArraySize])
        {}

    void push(const string& msg){
        msgArray[currentIdx++] = msg;
    }

    string pop(){
        auto msg = msgArray[currentIdx - 1];
        msgArray[currentIdx - 1] = "";
        --currentIdx;
        return msg;
    }

    bool full(){
        return ArraySize == currentIdx;
    }

    bool empty(){
        return 0 == currentIdx;
    }

    private:
        const int ArraySize;
        int currentIdx;
        std::string * msgArray;
};

int main(){
    Messages msgs(10);
    thread thr1([&msgs](){
        while(true){
            if(!msgs.full()){
                msgs.push("Hello");
            }
            else{
                break;
            }
        }
    });

    thread thr2([&msgs](){
        while(true){
            if(!msgs.empty()){
                cout << msgs.pop() << endl;
            }
            else{
                break;
            }
        }
    });

    thr1.detach();
    thr2.detach();

    using namespace chrono_literals;
    this_thread::sleep_for(2s);    

    return 0;
}

