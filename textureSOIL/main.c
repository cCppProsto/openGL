#include <stdio.h>

#include "glfw3.h"
#include <GL/gl.h>
#include "SOIL.h"

#define SCREEN_WIDTH        640
#define SCREEN_HEIGHT       480
#define IS_FULL_SCREEN      0

GLFWwindow* window;

GLuint load_texture(const char *);
void   draw_texture(int, int, int, int, GLuint);

int main()
{
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              "snow",
                              IS_FULL_SCREEN ? glfwGetPrimaryMonitor() : NULL,
                              NULL);

    glfwSetWindowPos(window,0,20);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glViewport(0, 0, (GLsizei)SCREEN_WIDTH, (GLsizei)SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);
    glfwSwapInterval(1);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_TEXTURE_2D);

    glPointSize(1);

    GLuint text[3];
    // path to texture, for working from QT IDE usually:
    // buildFolder/pics/test.png
    // for it case:
    // ../build/textureSOIL/
    text[0] = load_texture("pics/test.png");
    text[1] = load_texture("pics/info_128.png");
    text[2] = load_texture("pics/settings_128.png");

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        draw_texture(50, 50, 50, 50, text[0]);

        draw_texture(150, 50, 50, 50, text[1]);

        draw_texture(150, 150, 150, 150, text[2]);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
//------------------------------------------------------------------------------
GLuint load_texture(const char *apFileName)
{
    GLuint texture;
    texture = SOIL_load_OGL_texture(apFileName,
                                     SOIL_LOAD_AUTO,
                                     SOIL_CREATE_NEW_ID,
                                     SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
    return texture;
}
//------------------------------------------------------------------------------
void draw_texture(int aX, int aY, int aW, int aH, GLuint aTextID)
{
    glBindTexture(GL_TEXTURE_2D, aTextID);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glColor3f(255,255,255);
        glTexCoord2i(0, 0); glVertex2i(aX,      aY);
        glTexCoord2i(1, 0); glVertex2i(aX + aW, aY);
        glTexCoord2i(1, 1); glVertex2i(aX + aW, aY + aH);
        glTexCoord2i(0, 1); glVertex2i(aX,      aY + aH);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
