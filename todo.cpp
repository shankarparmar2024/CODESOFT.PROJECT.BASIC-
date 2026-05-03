#include <iostream>
#include <vector>
using namespace std;

// Structure to store task
struct Task {
    string description;
    bool completed;
};

// Function to display tasks
void viewTasks(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n--- TO-DO LIST ---\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;

        if (tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";

        cout << endl;
    }
}

// Function to add task
void addTask(vector<Task> &tasks) {
    Task newTask;
    cin.ignore(); // clear input buffer

    cout << "Enter task description: ";
    getline(cin, newTask.description);

    newTask.completed = false; // default = pending
    tasks.push_back(newTask);

    cout << "Task added successfully!\n";
}

// Function to mark task as completed
void markCompleted(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);

    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks[index - 1].completed = true;
    cout << "Task marked as completed!\n";
}

// Function to remove task
void removeTask(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);

    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed successfully!\n";
}

// Main function
int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markCompleted(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}