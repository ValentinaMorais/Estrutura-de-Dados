# Estrutura-de-Dados
Sistema de Escalonamento Hospitalar com Lista Circular
Este projeto apresenta uma implementação básica de um sistema de escalonamento para um hospital de grande porte, onde a complexidade da regra de negócio requer o uso de uma lista circular.
O objetivo é otimizar a alocação de turnos de forma justa, considerando diversos fatores, como especialidades médicas, preferências de horários e limitações individuais.

Funcionalidades Principais
Adição de Médicos à Lista Circular
A estrutura Doctor é utilizada para representar cada médico, incluindo informações como nome, especialidade, carga horária máxima semanal e preferência por turnos noturnos. 
A função addDoctor permite a adição de médicos à lista circular.

void addDoctor(Doctor** head, char name[], char specialty[], int maxWeeklyHours, int nightShiftPreference);
Escalonamento de Turnos

A função scheduleShifts realiza o escalonamento dos turnos, considerando a lista circular de médicos. 
A lógica de escalonamento pode ser personalizada para levar em conta especialidades, preferências de horários e limitações individuais.
void scheduleShifts(Doctor* head, int totalShifts);

Impressão da Lista Circular
A função printDoctors imprime a lista circular de médicos, exibindo suas informações relevantes.

void printDoctors(Doctor* head);

Exemplo de uso:
int main() {
    Doctor* doctorList = NULL;

    // Adição de médicos à lista circular
    addDoctor(&doctorList, "Dr. Smith", "Cardiologia", 40, 1);
    addDoctor(&doctorList, "Dr. Johnson", "Ortopedia", 35, 0);
    addDoctor(&doctorList, "Dr. Davis", "Pediatria", 30, 1);
    addDoctor(&doctorList, "Dr. Wilson", "Oncologia", 45, 1);

    // Escalonamento de 10 turnos
    int totalShifts = 10;
    scheduleShifts(doctorList, totalShifts);

    // Impressão da lista circular
    printDoctors(doctorList);

    return 0;
    }



Este projeto fornece uma base para a implementação de um sistema de escalonamento hospitalar, permitindo uma distribuição justa e contínua de turnos entre os médicos.
A lista circular garante que todos os médicos sejam considerados antes de reiniciar o processo, evitando privilégios constantes ou negligenciamento de profissionais no escalonamento.
