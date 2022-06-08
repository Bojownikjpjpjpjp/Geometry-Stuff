#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>
#include<vector>

class VBO
{
public:
	GLuint ID;
	
	//VBO(GLdouble* vertices, GLsizeiptr size);
	VBO(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};
#endif

