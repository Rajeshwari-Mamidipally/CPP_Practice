#include <iostream>
#include <string>
#include <ctime>  
using namespace std;
void delay_ms(int milliseconds) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}
class Command {
public:
    string name;
    int duration; 
    Command(string n, int d) : name(n), duration(d) {}
};
class CommandNode {
public:
    Command* cmd;
    CommandNode* next;
    CommandNode(Command* c) : cmd(c), next(NULL) {}
};
void advanceQueue(CommandNode*& current) {
    if (current != NULL) {
        current = current->next;
    }
}
void printQueue(CommandNode* head) {
    cout << "\n--- Command Queue ---\n";
    CommandNode* temp = head;
    while (temp != NULL) {
        cout << "Command: " << temp->cmd->name
             << ", Duration: " << temp->cmd->duration << "ms\n";
        temp = temp->next;
    }
}
class CommandExecutor {
public:
    void run(Command& c) {
        cout << "Executing Command: " << c.name << " for " << c.duration << "ms...\n";
        delay_ms(c.duration); 
        cout << "Completed: " << c.name << "\n";
    }
};
class CommandQueue {
public:
    CommandNode* head;
    CommandQueue() : head(NULL) {}
    void enqueue(Command* c) {
        CommandNode* newNode = new CommandNode(c);
        if (!head) {
            head = newNode;
        } else {
            CommandNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void executeNext(CommandNode*& current) {
        if (current == NULL) {
            cout << "No commands left to execute!\n";
            return;
        }
        CommandExecutor executor;
        executor.run(*current->cmd);
        advanceQueue(current); 
    }
    void executeAll() {
        CommandNode* current = head;
        while (current != NULL) {
            executeNext(current);
        }
    }
    void clear() {
        CommandNode* temp = head;
        while (temp != NULL) {
            CommandNode* toDelete = temp;
            temp = temp->next;
            delete toDelete->cmd; 
            delete toDelete;     
        }
        head = NULL;
    }
    ~CommandQueue() {
        clear();
    }
};
int main() {
    CommandQueue queue;
    cout << "Creating and enqueuing commands...\n";
    queue.enqueue(new Command("Start Motor", 100));
    queue.enqueue(new Command("Open Valve", 50));
    queue.enqueue(new Command("Stop Motor", 80));
    queue.enqueue(new Command("Close Valve", 60));
    queue.enqueue(new Command("Shutdown System", 120));
    printQueue(queue.head);
    cout << "\nExecuting commands one by one...\n";
    CommandNode* current = queue.head;
    while (current != NULL) {
        queue.executeNext(current);
    }
    cout << "\nAll commands executed.\n";
    printQueue(queue.head);
    cout << "Cleaning up memory...\n"; 
    return 0;
}