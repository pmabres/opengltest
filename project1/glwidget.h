#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include <QGLBuffer>
#include <QGLShaderProgram>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget( const QGLFormat& format, QWidget* parent = 0 );

protected:
    virtual void initializeGL();
    virtual void resizeGL( int w, int h );
    virtual void paintGL();

    virtual void keyPressEvent( QKeyEvent* e );

private:
    bool prepareShaderProgram( const QString& vertexShaderPath,
                               const QString& fragmentShaderPath );

    GLuint createTriangle();
    GLuint createShaders();
    GLuint createShader(GLenum shaderType, std::string shaderSource);
    bool checkShader(GLuint shader);
    std::string readFile(const char* fileName);

    QGLShaderProgram m_shader;
    QGLBuffer m_vertexBuffer;
};

#endif // GLWIDGET_H
