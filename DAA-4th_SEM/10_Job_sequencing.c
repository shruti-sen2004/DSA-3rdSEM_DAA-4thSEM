//Write a C program to implement Job sequencing with deadlines

#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit > ((struct Job *)a)->profit;
}

void jobSequencing(struct Job jobs[], int numJobs) {
    qsort(jobs, numJobs, sizeof(jobs[0]), compare);

    int maxDeadline = 0;
    int i;
    for (i = 0; i < numJobs; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    char result[maxDeadline];
    int slot[maxDeadline];
    for (i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    for (i = 0; i < numJobs; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                result[j] = jobs[i].id;
                break;
            }
        }
    }

    printf("The sequence of jobs is: ");
    for (i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("%c ", result[i]);
    }
}

int main() {
    int numJobs;
    int i;

    printf("Enter the number of jobs: ");
    scanf("%d", &numJobs);

    struct Job jobs[numJobs];

    for (i = 0; i < numJobs; i++) {
        printf("Enter the id, deadline and profit of job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, numJobs);

    return 0;
}

