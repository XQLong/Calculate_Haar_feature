#include <stdio.h>
int main()
{
    int i, x, y, sizeX, sizeY, width, height, count, c;

    /*全部5种Haar特征 */
    const int features = 5;
    const int feature[][2] = {{2,1}, {1,2}, {3,1}, {1,3}, {2,2}};
    const int frameSize = 24;

    count = 0;
    /* 遍历每种特征*/
    for (i = 0; i < features; i++) {
        sizeX = feature[i][0];
        sizeY = feature[i][1];
        printf("%dx%d shapes:\n", sizeX, sizeY);

        /* 每个特征的每种大小 */
        for (width = sizeX; width <= frameSize; width+=sizeX) {
            for (height = sizeY; height <= frameSize; height+=sizeY) {
                printf("\tsize: %dx%d => ", width, height);
                c=count;

                /* 每个特征的某种大小所在的不同位置 */
                for (x = 0; x <= frameSize-width; x++) {
                    for (y = 0; y <= frameSize-height; y++) {
                        count++;
                    }
                }
                printf("count: %d\n", count-c);
            }
        }
    }
    printf("%d\n", count);

    return 0;
}
