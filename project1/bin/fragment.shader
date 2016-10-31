#version 330 core
in vec3 ourColor;
out vec4 glColor;

void main()
{
    glColor = vec4(ourColor, 1.0f);
}
