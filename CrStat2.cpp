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

    str="�뤠���� �㬬� �����饭���� �।��";
    summcr=summs(str);
    str="�����饭��� �㬬� �।��";
    summvcr=summs(str);
    str="�뤠���� �㬬� �������饭���� �।��";
    summncr=summs(str);
    str="�������饭��� �㬬� �।��";
    summnvcr=summs(str);

    printf("������ �㬬� ��吝�� �ਡ뫨 �� ��� �� ��諮�� �����:");
    scanf("%f",&pry);
    prm=summvcr-summcr;
    pry+=prm;

    printf("\n������ �㬬� ��⪮� �� ��� �� ��諮�� �����:");
    scanf("%f",&uby);
    uby+=summncr;

    printf("\n������ �㬬� �ᥢ�� WMD �� ��諮�� �����:");
    scanf("%f",&wmd);
    wmd+=summnvcr;

    printf("\n������ �㬬� �뤠���� wmz �� ��� �� ������� � ��������� �� ��諮�� �����:");
    scanf("%f",&summcry);
    summcry+=summcr;
    summcry+=summncr;

    printf("\n������ �㬬� �����饭��� wmz �� ��� �� ��諮�� �����:");
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
    printf("��� �����襭�� ����� ������ 0\n");
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
