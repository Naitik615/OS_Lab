#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, frames_count;
    printf("Enter number of page references: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int pages[100];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    if (scanf("%d", &frames_count) != 1 || frames_count <= 0) return 1;

    int frames[20], time[20];
    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    int page_faults = 0;
    int counter = 0;

    printf("\nIncoming Page\tFrames State\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int flag1 = 0, flag2 = 0;

        // Check if page already present
        for (int j = 0; j < frames_count; j++) {
            if (frames[j] == page) {
                counter++;
                time[j] = counter;
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // Check for empty frame
        if (flag1 == 0) {
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] == -1) {
                    counter++;
                    page_faults++;
                    frames[j] = page;
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame, replace LRU
        if (flag2 == 0) {
            int pos = findLRU(time, frames_count);
            counter++;
            page_faults++;
            frames[pos] = page;
            time[pos] = counter;
        }

        printf("%d\t\t", page);
        for (int j = 0; j < frames_count; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        if (flag1 == 1)
            printf(" (Hit)\n");
        else
            printf(" (Miss)\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    printf("Total Page Hits = %d\n", n - page_faults);

    return 0;
}

