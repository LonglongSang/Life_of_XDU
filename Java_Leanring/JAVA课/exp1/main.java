/**
File Name:main.java
Authro: Sang Longlong
 */
import java.util.Scanner;
class calender
{
    private static int[] monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static int beginYear=1900;
    private static int offset=1;//0表示1990年1月1日是星期1
    private static char sep = ' ';
    private static boolean isLeapYear(int year)
    {
        return (year % 4 ==0 && year % 100 != 0) || year % 400 == 0;
    }
    private static int getDays(int year, int month)
    {
        return monthDays[month] + ((isLeapYear(year) && month == 1) ? 1 : 0);
    }
    public static int weekday(int year, int month, int day)
    {
        month--;
        day--;
        if(year<beginYear || month < 0 || month >= 12 || day < 0 || day >= getDays(year, month)) return -1;
        int total = 0;
        for(int i = beginYear; i < year; i++)
        {
            for(int j = 0; j < 12; j++)
            {
                total += getDays(i, j);
            }
        }
        for(int i = 0; i < month; i++)
        {
            total += getDays(year, i);
        }
        total += day;
        return (total + offset) % 7;
    }
    private static int getLen(int day)
    {
        if(day == 0) return 0;
        if(day < 10) return 1;
        else return 2;
    }
    private static void print(int offset, int day)
    {
        int[] len = {3, 3, 4, 3, 4, 3, 3};
        if(offset != 0) System.out.printf("%c", sep);
        for(int i = 0; i < len[offset] - getLen(day); i++) System.out.printf(" ");
        if(day != 0) System.out.printf("%d", day);
    }
    public static void printCalender(int year)
    {
        if(year < beginYear) return;
        int month = 1, day = 1, offset = weekday(year, month, day);
        for(int i = 0; i < 12; i++)
        {
            System.out.printf("           %d %d\n", year, i + 1);
            System.out.printf("Sun%cMon%cTues%cWed%cThur%cFri%cSat\n", sep, sep, sep, sep, sep, sep);
            for(int j = 0; j < offset; j++) print(j, 0);
            for(int j = 0, days = getDays(year, i); j < days; j++ )
            {
                print(offset++, j + 1);
                offset %= 7;
                if(offset == 0) System.out.printf("\n");
            }
            if(offset !=0 ) System.out.printf("\n");
        }

    }
}
public class main
{
    public static void main(String []args)
    {
        int year, month, day;
        year = 1900;
        month = 1;
        day = 1;

        
        //星期1到星期6用1-6表示，星期日用0表示
        
        int typ;
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            System.out.printf("Please input choose your mode 1 for weekday, 2 for calender 3 for exit\n");
            typ = sc.nextInt();
            if(typ == 1)
            {
                year = sc.nextInt();
                month = sc.nextInt();
                day = sc.nextInt();
                System.out.printf("%d年%d月%d日是星期 %d\n", year, month, day, calender.weekday(year,month,day));//如果这一天不存在，输出-1
            }else if(typ == 2)
            {
                year = sc.nextInt();
                calender.printCalender(year);//输出2020年的日历
            }else
            {
                break;
            }
        }
    }
}