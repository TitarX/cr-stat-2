#include <stdio.h>
#include <conio.h>

float summs(char*);

main()
{
    clrscr();
    char *str;
    float summcr,summvcr,summncr,summnvcr;
    float prm,pry,uby,wmd;
    float summcry,summvcry,commwm,commcr,result;

    str="Выданная сумма возвращенного кредита";
    summcr=summs(str);
    str="Возвращенная сумма кредита";
    summvcr=summs(str);
    str="Выданная сумма невозвращенного кредита";
    summncr=summs(str);
    str="Невозвращенная сумма кредита";
    summnvcr=summs(str);

    printf("Введите сумму грязной прибыли за год от прошлого месяца:");
    scanf("%f",&pry);
    prm=summvcr-summcr;
    pry+=prm;

    printf("\nВведите сумму убытков за год от прошлого месяца:");
    scanf("%f",&uby);
    uby+=summncr;

    printf("\nВведите сумму осевших WMD от прошлого месяца:");
    scanf("%f",&wmd);
    wmd+=summnvcr;

    printf("\nВведите сумму выданных wmz за год по возврату и невозврату от прошлого месяца:");
    scanf("%f",&summcry);
    summcry+=summcr;
    summcry+=summncr;

    printf("\nВведите сумму возвращенных wmz за год от прошлого месяца:");
    scanf("%f",&summvcry);
    summvcry+=summvcr;

    commwm=summcry/100*0.8;
    commcr=summvcry/100*0.1;
    result=pry-uby-commwm-commcr;

    FILE *statFile;
    statFile=fopen("stat.txt","w");
    fprintf(statFile,"Vozvrat\n\n%.2f/%.2f (%.2f)\n",summcr,summvcr,prm);
    fprintf(statFile,"gryaznaya pribul=%.2f\n\n",pry);
    fprintf(statFile,"**********************************************\n\n");
    fprintf(statFile,"Ne vozvrat\n\n(%.2f)/%.2f\n",summncr,summnvcr);
    fprintf(statFile,"ubutok=%.2f\n\n",uby);
    fprintf(statFile,"**********************************************\n\n");
    fprintf(statFile,"Osevshie WMD=%.2f\n\n",wmd);
    fprintf(statFile,"**********************************************\n\n");
    fprintf(statFile,"Itog za god\n\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",summcry,summvcry,commwm,commcr,result);
    fclose(statFile);
    getchar();
    getch();
    return 0;
}

float summs(char*s)
{
    float a=1,summ=0;
    int i=0;
    printf("Для завершения ввода введите 0\n");
    while(a!=0)
    {
        i++;
        printf("\n%s %d:",s,i);
        scanf("%f",&a);
        summ+=a;
    }
    printf("\n\n");
    return summ;
}
