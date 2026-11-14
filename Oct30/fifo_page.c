#include <stdio.h>

int main() {
    int n, frames_count;
    printf("Enter number of page references: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int pages[100];
    printf("Enter reference string (page numbers): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    if (scanf("%d", &frames_count) != 1 || frames_count <= 0) return 1;

    int frames[20];
    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1;
    }

    int page_faults = 0;
    int index = 0;

    printf("\nIncoming Page\tFrames State\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page already exists in frames
        for (int j = 0; j < frames_count; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[index] = page;
            index = (index + 1) % frames_count;
            page_faults++;

            printf("%d\t\t", page);
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf(" (Miss)\n");
        } else {
            printf("%d\t\t", page);
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf(" (Hit)\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    printf("Total Page Hits = %d\n", n - page_faults);

    return 0;
}

