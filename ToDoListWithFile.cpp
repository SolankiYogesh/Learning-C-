#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> // Add at the top

using namespace std;

struct Task
{
    string description;
    bool completed;
};

Task addTask()
{
    string description;
    cin.ignore();
    cout << "Please enter task description" << endl;
    getline(cin, description);
    Task task;
    task.description = description;
    task.completed = false;
    return task;
}

void viewTasks(vector<Task> tasks)
{
    if (tasks.size() > 0)
    {
        cout << "\n--- To-Do List ---\n";
    }
    for (int i = 0; i < tasks.size(); i++)
    {
        string status;
        if (tasks[i].completed)
        {
            status = " ✅ ";
        }
        else
        {
            status = " ❌ ";
        }
        cout << "[" << i + 1 << "] " << status << " " << tasks[i].description << endl;
    }
}

vector<Task> markAsComplete(vector<Task> tasks, int index)
{
    const int currentIndex = index - 1;
    if (tasks.size() > currentIndex)
    {
        if (tasks[currentIndex].completed)
        {
            cout << "Task already marked as complete!" << endl;
        }
        else
        {
            tasks[currentIndex].completed = true;
        }
    }
    else
    {
        cout << "wrong choice!" << endl;
    }

    return tasks;
}

vector<Task> deleteTask(int index, vector<Task> tasks)
{
    const int currentIndex = index - 1;
    if (tasks.size() > currentIndex)
    {
        char confirm;
        cout << "Are you sure you want to delete this task? (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y')
        {
            tasks.erase(tasks.begin() + currentIndex);
            cout << "Task deleted!" << endl;
        }
        else
        {
            cout << "Task not deleted." << endl;
        }
    }
    else
    {
        cout << "wrong choice!" << endl;
    }

    return tasks;
}

void addToFile(vector<Task> tasks)
{
    ofstream file("tasks.txt", ios::trunc);
    for (int i = 0; i < tasks.size(); i++)
    {
        string status = tasks[i].completed ? "true" : "false";
        file << status << "," << tasks[i].description << endl;
    }
    file.close();
}

int main()
{

    int choice;
    vector<Task> tasks;
    ifstream file("tasks.txt");
    string line;
    if (file)
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            string status, description;

            getline(ss, status, ',');
            getline(ss, description); // Remaining whole line (even with commas)

            Task task;
            task.completed = status == "true";
            task.description = description;
            tasks.push_back(task);
        }
    }

    do
    {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Task task = addTask();
            tasks.push_back(task);
            addToFile(tasks);
            cout << "Task Added!" << endl;
            break;
        }
        case 2:
            viewTasks(tasks);
            break;
        case 3:
        {
            int index;
            cout << "Please enter number to mark" << endl;
            cin >> index;
            tasks = markAsComplete(tasks, index);
            addToFile(tasks);
            break;
        }
        case 4:
        {
            int index;
            cout << "Please enter number to delete" << endl;
            cin >> index;
            tasks = deleteTask(index, tasks);
            addToFile(tasks);

            break;
        }
        case 5:
            exit(0);
            break;

        default:
            break;
        }

    } while (choice != 5);

    return 0;
}
