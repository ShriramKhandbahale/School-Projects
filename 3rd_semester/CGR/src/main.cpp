#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void sdelay(double);
void print_circle();
void print_eyes();
void print_smile();
void print_emoji();
void print_project_info();
void print_group_members();
void print_group_info();
void print_group_info_static();

int main()
{
    system("start ../assets/bgm.mp3");

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    print_circle();
    print_eyes();
    print_smile();

    sleep(1);
    sdelay(0.12);

    print_emoji();

    sleep(22);

    print_group_info();
    getch();

    closegraph();
    return 0;
}

void sdelay(double dly)
{
    const clock_t start = clock();
    clock_t current;
    do
    {
        current = clock();
    } while ((double)(current - start) / CLOCKS_PER_SEC < dly);
}

void print_circle()
{
    setcolor(RED);
    for (int i = 0; i < 360; i++)
    {
        if (i == 1)
        {
            cleardevice();
        }
        arc(300, 250, 0, i, 100);
        sdelay(0.01);
    }
}

void print_eyes()
{
    for (int i = 0; i < 360; i++)
    {
        circle(300, 250, 100);

        ellipse(340, 220, 0, i, 20, 25);
        ellipse(255, 220, 0, i, 20, 25);

        if (i == 2)
        {
            cleardevice();
        }
    }

    for (int i = 0; i < 360; i++)
    {
        circle(300, 250, 100);

        ellipse(340, 220, 0, 360, 20, 25);
        ellipse(255, 220, 0, 360, 20, 25);

        ellipse(255, 225, 0, i, 15, 20);
        ellipse(340, 225, 0, i, 15, 20);

        if (i == 2)
        {
            cleardevice();
        }
        sdelay(0.005);
    }
}

void print_smile()
{
    for (int i = 350; i >= 250; i--)
    {
        line(350, 270, i, 270);
        sdelay(0.01);
    }

    for (int i = 180; i <= 360; i++)
    {

        if (i == 180)
        {
            cleardevice();
        }

        circle(300, 250, 100);
        line(250, 270, 350, 270);
        ellipse(340, 220, 0, 360, 20, 25);
        ellipse(255, 220, 0, 360, 20, 25);
        ellipse(255, 225, 0, 360, 15, 20);
        ellipse(340, 225, 0, 360, 15, 20);

        arc(300, 270, 180, i, 50);

        if (i == 181)
        {
            cleardevice();
        }

        sdelay(0.008);
    }
}

void print_emoji()
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);

    circle(300, 250, 100);
    floodfill(300, 250, YELLOW);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    pieslice(300, 270, 180, 360, 50);

    ellipse(255, 220, 0, 360, 20, 25);
    floodfill(256, 221, WHITE);
    ellipse(340, 220, 0, 360, 20, 25);
    floodfill(341, 221, WHITE);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    ellipse(255, 225, 0, 360, 15, 20);
    floodfill(256, 231, BLACK);

    ellipse(340, 225, 0, 360, 15, 20);
    floodfill(341, 231, BLACK);
}

void print_project_info()
{
    setcolor(RGB(0, 255, 0));
    outtextxy(200, 180, "CGR Micro-Project | Group no - 14.");
}

void print_group_members()
{
    sleep(1);
    outtextxy(240, 220, "53. Durvesh Bhuse");
    sleep(1);
    // sdelay(0.02);

    outtextxy(240, 250, "54. Nidhi Gangurde");
    sdelay(0.60);

    outtextxy(225, 280, "55. Shriram Khandbahale");
    sdelay(0.60);

    outtextxy(240, 310, "56. Shrihari Mogal");
    sleep(2);
    sdelay(0.08);
}

void print_group_info()
{
    cleardevice();
    print_project_info();
    sdelay(0.05);
    cleardevice();
    print_emoji();
    sdelay(0.05);
    cleardevice();
    print_project_info();
    sdelay(0.05);
    cleardevice();
    print_emoji();
    sdelay(0.05);
    cleardevice();
    print_project_info();

    print_group_members();

    cleardevice();
    print_group_info_static();
    sdelay(0.05);
    cleardevice();
    print_emoji();
    sdelay(0.05);
    cleardevice();
    print_group_info_static();
    sdelay(0.05);
    cleardevice();
    print_emoji();
    cleardevice();
    print_group_info_static();
    sdelay(0.05);
    cleardevice();
    print_emoji();
}

void print_group_info_static()
{
    outtextxy(200, 180, "CGR Micro-Project | Group no - 14.");
    outtextxy(240, 220, "53. Durvesh Bhuse");
    outtextxy(240, 250, "54. Nidhi Gangurde");
    outtextxy(225, 280, "55. Shriram Khandbahale");
    outtextxy(240, 310, "56. Shrihari Mogal");
}