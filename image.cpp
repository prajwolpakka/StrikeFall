#include "image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void image(char I[50]) {
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_BINDING_2D);
//glBlendFunc(GL)
    int width, height, nrChannels;
    glEnable(GL_TEXTURE_2D);
    unsigned char *data = stbi_load(I, &width, &height, &nrChannels, 0);
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
// set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        gluBuild2DMipmaps(GL_TEXTURE_2D,GL_RGB,width,height,GL_RGB,GL_UNSIGNED_BYTE,data);
    } else {
        printf("Failed to load texture \n");
    }

    glScalef(1,-1,1);
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    //front
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2i(0,0);
    glVertex3f(-10.0,-10.0,10.0);
    glTexCoord2i(1,0);
    glVertex3f(10.0,-10.0,10.0);
    glTexCoord2i(1,1);
    glVertex3f(10.0,10.0,10.0);
    glTexCoord2i(0,1);
    glVertex3f(-10.0,10.0,10.0);
    glEnd();
//
    stbi_image_free(data);
    glDisable(GL_TEXTURE_2D);
}
