#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task 
{
    string description;
    bool isCompleted;
    Task(string desc) : description(desc), isCompleted(false) {}
};
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() 
{
    vector<Task> tasks;
    int choice;
    do 
    {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void addTask(vector<Task>& tasks) 
{
    string description;
    cout << "Enter the task description: ";
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added successfully." << endl;
}
void viewTasks(const vector<Task>& tasks) 
{
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
        return;
    }
    cout << "\nTask List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << (tasks[i].isCompleted ? " [Completed]" : " [Pending]") 
             << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks) 
{
    if (tasks.empty()) {
        cout << "No tasks to mark as completed." << endl;
        return;
    }
    viewTasks(tasks);
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    cin.ignore(); 

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[index - 1].isCompleted = true;
    cout << "Task marked as completed." << endl;
}

void removeTask(vector<Task>& tasks)
{
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        return;
    }
    viewTasks(tasks);
    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;
    cin.ignore(); 

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed successfully." << endl;
}
