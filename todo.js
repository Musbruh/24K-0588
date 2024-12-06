let tasks = [];

function displayMenu()
{
    console.log(`
    To-Do List Manager
    ------------------
    1. Add Task
    2. Remove Task
    3. View Tasks
    4. Clear Tasks
    5. Exit
    `);
}

function addTask()
{
    let task = prompt("Enter a new task:");
    if (task)
    {
        tasks.push(task);
        console.log(`Task "${task}" added successfully!`);
    }
    else
    {
        console.log("No task entered. Task not added.");
    }
}

function removeTask()
{
    if (tasks.length === 0)
    {
        console.log("No tasks to remove.");
        return;
    }

    console.log("Current Tasks:");
    tasks.forEach((task, index) => console.log(`${index + 1}. ${task}`));
    let taskNumber = parseInt(prompt("Enter the task number to remove:"), 10);

    if (!isNaN(taskNumber) && taskNumber > 0 && taskNumber <= tasks.length)
    {
        let removedTask = tasks.splice(taskNumber - 1, 1);
        console.log(`Task "${removedTask}" removed successfully!`);
    }
    else
    {
        console.log("Invalid task number. No task removed.");
    }
}

function viewTasks()
{
    if (tasks.length === 0)
    {
        console.log("No tasks in the list.");
    }
    else
    {
        console.log("Current Tasks:");
        tasks.forEach((task, index) => console.log(`${index + 1}. ${task}`));
    }
}

function clearTasks()
{
    if (tasks.length === 0)
    {
        console.log("No tasks to clear.");
    }
    else
    {
        tasks = [];
        console.log("All tasks cleared.");
    }
}

function main()
{
    let choice;

    do
    {
        displayMenu();
        choice = parseInt(prompt("Choose an option (1-5):"), 10);

        switch (choice)
        {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                viewTasks();
                break;
            case 4:
                clearTasks();
                break;
            case 5:
                console.log("Exiting the program. Goodbye!");
                break;
            default:
                console.log("Invalid choice. Please enter a number between 1 and 5.");
        }
    } while (choice !== 5);
}

main();
