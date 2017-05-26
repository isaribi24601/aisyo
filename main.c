//
//  main.c
//  study
//
//  Created by 加藤空知 on 2017/05/01.
//  Copyright © 2017年 加藤空知. All rights reserved.
//

#include <stdio.h>
#include <memory.h>
#include <string.h>

int main(void)
{
    /* for用共通値 */
    int i,ch;
    /* 名前の入力 */
    char name_first[100];
    char name_second[100];
    printf("Enter 1st name.\n");
    scanf("%s",name_first);
    printf("Enter 2nd name.\n");
    scanf("%s",name_second);
    
    /* 名前変換後の数値用配列 */
    int nameCode[100];
    
    /*　数値化処理1 */
    for (i=0,ch=0; name_first[i]!= '\0'; i++,ch++){
        switch ((int)name_first[i]) {
                /* 行 */
            case 97:
                nameCode[i]=1;
                break;
            case 105:
                nameCode[i]=2;
                break;
            case 117:
                nameCode[i]=3;
                break;
            case 101:
                nameCode[i]=4;
                break;
            case 111:
                nameCode[i]=5;
                break;
                /* 列 */
                /* aは行の処理と重複、省略 */
            case 107:
            case 103:
                nameCode[i]=2;
                break;
            case 115:
            case 122:
                nameCode[i]=3;
                break;
            case 116:
            case 100:
                nameCode[i]=4;
                break;
            case 110:
                nameCode[i]=5;
                break;
            case 104:
            case 98:
            case 112:
                nameCode[i]=6;
                break;
            case 109:
                nameCode[i]=7;
                break;
            case 121:
                nameCode[i]=8;
                break;
            case 114:
                nameCode[i]=9;
                break;
            case 119:
                nameCode[i]=0;
                break;
                /* 「ん」のみ通常入力不可 */
            default:
                nameCode[i]=0;
                break;
        }
    }

    /*　数値化処理2 */
    for (i=0; name_second[i]!= '\0'; i++){
        switch ((int)name_second[i]) {
                /* 行 */
            case 97:
                nameCode[ch+i]=1;
                break;
            case 105:
                nameCode[ch+i]=2;
                break;
            case 117:
                nameCode[ch+i]=3;
                break;
            case 101:
                nameCode[ch+i]=4;
                break;
            case 111:
                nameCode[ch+i]=5;
                break;
                /* 列 */
                /* aは行の処理と重複、省略 */
            case 107:
            case 103:
                nameCode[ch+i]=2;
                break;
            case 115:
            case 122:
                nameCode[ch+i]=3;
                break;
            case 116:
            case 100:
                nameCode[ch+i]=4;
                break;
            case 110:
                nameCode[ch+i]=5;
                break;
            case 104:
            case 98:
            case 112:
                nameCode[ch+i]=6;
                break;
            case 109:
                nameCode[ch+i]=7;
                break;
            case 121:
                nameCode[ch+i]=8;
                break;
            case 114:
                nameCode[ch+i]=9;
                break;
            case 119:
                nameCode[ch+i]=0;
                break;
                /* 「ん」のみ通常入力不可 */
            default:
                nameCode[ch+i]=0;
                break;
        }
    }
//    for (i=0; nameCode[i]!= '\0'; i++) {
//                printf("%d",nameCode[i]);
//            }


    /* 要素足し合わせの準備 */
    
    static int newArray[30] = {};
    
    /* 配列の要素数が２になるまで */
    while (nameCode[2] != 0 && nameCode[3] != 0) {
    /* 足し合わせを繰り返す */
    for (i=0; i != sizeof(nameCode)/sizeof(nameCode[0]); i += 2) {
        int sum = 0;
        sum = nameCode[i] + nameCode[i+1];
        
        /* 10以上になった時の分岐処理 */
        if (sum >= 10) {
            sum = sum - 10;
        }
    //printf("%d",sum);
        newArray[i/2] = sum;
    }
//    for (i=0; i < 20; i++) {
//        printf("%d",newArray[i]);
//    }
    
    /* nameCodeの再初期化 */
    for (i=0; i != sizeof(nameCode)/sizeof(nameCode[0]); i++) {
        nameCode[i]=0;
    }
   /* nameCodeにnewArrayの値を代入 */
        for (i=0; i != sizeof(newArray)/sizeof(newArray[0]); i++) {
            nameCode[i] = newArray[i];
        }
    
    /* newArrayの再初期化 */
    for (i=0; i != sizeof(newArray)/sizeof(newArray[0]); i++){
        newArray[i]=0;
    }
    
}
    
    /* 結果の表示 */
    printf("Compatibility is %d%d %%.",nameCode[0],nameCode[1]);
 
    /* 確認用 */
//    for (i=0; i != sizeof(nameCode)/sizeof(nameCode[0]); i++) {
//        printf("%d",nameCode[i]);
//    }
//    for (i=0; i < 10; i++) {
//        printf("%d",newArray[i]);
//    }
    //printf("%d",ch);

    return 0;
}
