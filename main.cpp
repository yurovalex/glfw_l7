#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

//Точки для треугольника
float pointA[4];
float pointB[4];
float pointC[4];

//Матрица для преобразований
float matrix_data[4][4];

void initData(size_t m_size)
{
    //Точки треугольника
    pointA[0] = -0.6;  pointA[1] = -0.4;  pointA[2] = 0.; pointA[3] =1.;
    pointB[0] =  0.6;  pointB[1] = -0.4;  pointB[2] = 0.; pointB[3] =1.;
    pointC[0] =  0.;   pointC[1] =  0.6;  pointC[2] = 0.; pointC[3] =1.;
    //Единичная матрица
    //1 0 0 0
    //0 1 0 0
    //0 0 1 0
    //0 0 0 1
    for (size_t i = 0; i < m_size; i++)
    {
        for (size_t j = 0; j < m_size; j++)
        {
            matrix_data[i][j] = (i == j) ? 1: 0;
        }
    }
}

float* marix_mul_vect(float *somePoint, int m_size)
{
    static float newPoint [4] = {0,0,0,1};
    for (size_t i = 0; i < m_size; i++)
    {
        float temp = 0;
        for (size_t j = 0; j < m_size; j++)
        {
            temp += somePoint[j] * matrix_data[i][j];
        }
        newPoint[i] = temp;
    }
    return newPoint;
}


float* rotatingX(float *somePoint, int m_size, float Cx, float Ix)
{
    matrix_data[1][1] = Cx;
    matrix_data[1][2] = Ix;
    matrix_data[2][1] = -Ix;
    matrix_data[2][2] = Cx;
    return marix_mul_vect(somePoint, 4);
}

float* rotatingY(float *somePoint, int m_size, float Cy, float Iy)
{
    matrix_data[0][0] = Cy;
    matrix_data[2][0] = Iy;
    matrix_data[0][2] = -Iy;
    matrix_data[2][2] = Cy;
    return marix_mul_vect(somePoint, 4);
}

float* rotatingZ(float *somePoint, int m_size, float Cz, float Iz)
{
    matrix_data[0][0] = Cz;
    matrix_data[0][1] = Iz;
    matrix_data[1][0] = -Iz;
    matrix_data[1][1] = Cz;
    return marix_mul_vect(somePoint, 4);
}

float* moving(float *somePoint, int m_size, float Tx = 0, float Ty = 0, float Tz = 0)
{
    matrix_data[0][3] = Tx;
    matrix_data[1][3] = Ty;
    matrix_data[2][3] = Tz;
    return marix_mul_vect(somePoint, 4);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_I)
    {
        initData(4);
    }

    if (key == GLFW_KEY_LEFT)
    {
        float *pntA = moving(pointA, 4, -0.01);
        pointA[0] = pntA[0]; pointA[1] = pntA[1]; pointA[2] = pntA[2];

        float *pntB = moving(pointB,4, -0.01);
        pointB[0] = pntB[0]; pointB[1] = pntB[1]; pointB[2] = pntB[2];

        float *pntC = moving(pointC,4, -0.01);
        pointC[0] = pntC[0]; pointC[1] = pntC[1]; pointC[2] = pntC[2];

    }

    if (key == GLFW_KEY_RIGHT)
    {
        float *pntA = moving(pointA, 4, 0.01);
        pointA[0] = pntA[0]; pointA[1] = pntA[1]; pointA[2] = pntA[2];

        float *pntB = moving(pointB,4, 0.01);
        pointB[0] = pntB[0]; pointB[1] = pntB[1]; pointB[2] = pntB[2];

        float *pntC = moving(pointC,4, 0.01);
        pointC[0] = pntC[0]; pointC[1] = pntC[1]; pointC[2] = pntC[2];

    }

    if (key == GLFW_KEY_UP)
    {
        float *pntA = moving(pointA, 4, 0, 0.01);
        pointA[0] = pntA[0]; pointA[1] = pntA[1]; pointA[2] = pntA[2];

        float *pntB = moving(pointB, 4, 0, 0.01);
        pointB[0] = pntB[0]; pointB[1] = pntB[1]; pointB[2] = pntB[2];

        float *pntC = moving(pointC, 4, 0, 0.01);
        pointC[0] = pntC[0]; pointC[1] = pntC[1]; pointC[2] = pntC[2];
    }

    if (key == GLFW_KEY_DOWN)
    {
        float *pntA = moving(pointA, 4, 0, -0.01);
        pointA[0] = pntA[0]; pointA[1] = pntA[1]; pointA[2] = pntA[2];

        float *pntB = moving(pointB, 4, 0, -0.01);
        pointB[0] = pntB[0]; pointB[1] = pntB[1]; pointB[2] = pntB[2];

        float *pntC = moving(pointC, 4, 0, -0.01);
        pointC[0] = pntC[0]; pointC[1] = pntC[1]; pointC[2] = pntC[2];
    }

    if (key == GLFW_KEY_X)
    {
        float *pntA = rotatingX(pointA, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointA[0] = pntA[0]; pointA[1] = pntA[1]; pointA[2] = pntA[2];

        float *pntB = rotatingX(pointB, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointB[0] = pntB[0]; pointB[1] = pntB[1]; pointB[2] = pntB[2];

        float *pntC = rotatingX(pointC, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointC[0] = pntC[0]; pointC[1] = pntC[1]; pointC[2] = pntC[2];
    }

    if (key == GLFW_KEY_Y)
    {
        float *pntA = rotatingY(pointA, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointA[0] = pntA[0]; pointA[1] = pntA[1]; pointA[2] = pntA[2];

        float *pntB = rotatingY(pointB, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointB[0] = pntB[0]; pointB[1] = pntB[1]; pointB[2] = pntB[2];

        float *pntC = rotatingY(pointC, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointC[0] = pntC[0]; pointC[1] = pntC[1]; pointC[2] = pntC[2];
    }

    if (key == GLFW_KEY_Z)
    {
        float *pntA = rotatingZ(pointA, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointA[0] = pntA[0]; pointA[1] = pntA[1]; pointA[2] = pntA[2];

        float *pntB = rotatingZ(pointB, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointB[0] = pntB[0]; pointB[1] = pntB[1]; pointB[2] = pntB[2];

        float *pntC = rotatingZ(pointC, 4, cos(M_PI_2/20), (sin(M_PI_2/20)));
        pointC[0] = pntC[0]; pointC[1] = pntC[1]; pointC[2] = pntC[2];
    }
}

int main()
{
    initData(4);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    GLFWwindow* window = glfwCreateWindow(1024, 768, "Matrix Operation", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = (float) width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.5f,0.5f,0.5f,1);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //glRotatef((float)glfwGetTime() * 60.f, 0.f, 1.f, 1.f);

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(pointA[0], pointA[1], pointA[2]);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(pointB[0], pointB[1], pointB[2]);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(pointC[0], pointC[1], pointC[2]);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSetKeyCallback(window, key_callback);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
