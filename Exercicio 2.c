#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da tarefa
typedef struct Task {
    char name[50];
    int priority;
    char status[20];
    struct Task* next;
    struct Task* prev;
} Task;

// Função para inserir uma nova tarefa na lista
void insertTask(Task** head, char name[], int priority, char status[]) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    if (!newTask) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newTask->name, name);
    newTask->priority = priority;
    strcpy(newTask->status, status);
    newTask->next = NULL;

    if (*head == NULL || priority > (*head)->priority) {
        newTask->next = *head;
        newTask->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newTask;
        }
        *head = newTask;
    } else {
        Task* current = *head;
        while (current->next != NULL && priority <= current->next->priority) {
            current = current->next;
        }
        newTask->next = current->next;
        newTask->prev = current;
        if (current->next != NULL) {
            current->next->prev = newTask;
        }
        current->next = newTask;
    }
}

// Função para remover uma tarefa da lista
void removeTask(Task** head, Task* taskToRemove) {
    if (taskToRemove->prev != NULL) {
        taskToRemove->prev->next = taskToRemove->next;
    } else {
        *head = taskToRemove->next;
    }

    if (taskToRemove->next != NULL) {
        taskToRemove->next->prev = taskToRemove->prev;
    }

    free(taskToRemove);
}

// Função para consultar a tarefa com a prioridade mais alta que não foi concluída
Task* getHighestPriorityUnfinishedTask(Task* head) {
    Task* current = head;
    while (current != NULL) {
        if (strcmp(current->status, "concluída") != 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Função para imprimir todas as tarefas na lista
void printTasks(Task* head) {
    Task* current = head;
    while (current != NULL) {
        printf("Nome: %s, Prioridade: %d, Status: %s\n", current->name, current->priority, current->status);
        current = current->next;
    }
}

// Função principal de exemplo
int main() {
    Task* taskList = NULL;

    // Exemplo de inserção de tarefas
    insertTask(&taskList, "Tarefa 1", 3, "pendente");
    insertTask(&taskList, "Tarefa 2", 5, "em progresso");
    insertTask(&taskList, "Tarefa 3", 2, "pendente");
    insertTask(&taskList, "Tarefa 4", 5, "pendente");

    // Exemplo de remoção de uma tarefa
    Task* taskToRemove = taskList->next->next;
    removeTask(&taskList, taskToRemove);

    // Exemplo de consulta da tarefa com a prioridade mais alta não concluída
    Task* highestPriorityUnfinishedTask = getHighestPriorityUnfinishedTask(taskList);
    if (highestPriorityUnfinishedTask != NULL) {
        printf("Tarefa de maior prioridade não concluída: %s\n", highestPriorityUnfinishedTask->name);
    } else {
        printf("Não há tarefas não concluídas.\n");
    }

    // Exemplo de impressão de todas as tarefas
    printTasks(taskList);

    return 0;
}
