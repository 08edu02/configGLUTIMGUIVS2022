#include "GL/glut.h"
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl3.h"

void inicializar()
{
    glClearColor(0, 1, 1, 0);
}

float colorTriangulo[3] = { 0.0f, 0.0f, 0.0f };

void graficar()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGLUT_NewFrame();
    ImGui::NewFrame();
    ImGuiIO& io = ImGui::GetIO();

    glClear(GL_COLOR_BUFFER_BIT);

    ImGui::Begin("Ventana ImGUI");
        ImGui::Text("Texto prueba");
        ImGui::ColorEdit3("Color", colorTriangulo);
    ImGui::End();

    ImGui::Render();
    glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);

    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glColor3f(colorTriangulo[0], colorTriangulo[1], colorTriangulo[2]);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.2, 0.7);
        glVertex2f(0.5, 0.1);
        glVertex2f(-0.2, -0.5);
    glEnd();

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Hola Mundo");

    inicializar();

    glutDisplayFunc(graficar);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    ImGui_ImplGLUT_Init();
    ImGui_ImplOpenGL3_Init();

    ImGui_ImplGLUT_InstallFuncs();

    glutMainLoop();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();

    return 0;
}