#include <iostream>
#include <glad/glad.h>
#include <Glfw/glfw3.h>	
#include <vector>

#include"PUNKT.h"
#include"LINIA.h"
#include"FUNKCJE.h"
#include"WIELOKAT.h"
#include"Obliczeniowe.h"

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

int main()
{
	solve();
	
#pragma region window_initializer
	// Initialize GLFW
	glfwInit();
	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Create a GLFWwindow object of 1400 by900 pixels, naming it "Geometria program wyswietlajacy"
	GLFWwindow* window = glfwCreateWindow(900, 900, "Geometria program wyswietlajacy", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 1400, y = 900
	glViewport(0, 0, 900, 900);
#pragma endregion

#pragma region dane_do_uk³adu_wspó³rzêdnych
	PUNKT lewy = PUNKT(-1, 0);
	PUNKT prawy = PUNKT(1, 0);
	PUNKT gora = PUNKT(0, 1);
	PUNKT dol = PUNKT(0, -1);
	LINIA ox = generuj_prosta_z_lini(LINIA(lewy, prawy));
	LINIA oy = generuj_prosta_z_lini(LINIA(gora, dol));
#pragma endregion

#pragma region input_dla_losowej_lini_i_losowego_punktu_-_sprawdzanie_wzajemnego_polozenia
	//
	//PUNKT badany_punkt = losuj_punkt();
	//LINIA losowa_prosta = generuj_prosta_z_lini(generuj_linie_z_2_losowych_punktow());

	//z_ktorej_strony_prostej(losowa_prosta, badany_punkt);
	//badany_punkt.wypisz();
	//losowa_prosta.wypisz();
	//
#pragma endregion
#pragma region losowy_trójk¹t_i_losowy_punkt_-_Sprawdzenie_wzajemnego_po³o¿enia
	//PUNKT badany_punkt = losuj_punkt();
	//PUNKT w1 = losuj_punkt();
	//PUNKT w2 = losuj_punkt();
	//PUNKT w3 = losuj_punkt();
	//LINIA l1 = LINIA(w1, w2);
	//LINIA l2 = LINIA(w2, w3);
	//LINIA l3 = LINIA(w3, w1);

	//if (czy_w_trojkacie(w1, w2, w3, badany_punkt)) {
	//	std::cout << "\n punkt lezy w trojkacie\n";
	//}
	//badany_punkt.wypisz();

	
#pragma endregion

#pragma region wielok¹t_i_punkt
	PUNKT* punkty = new PUNKT[20];
	for (int i = 0; i < 10; i++) {
		punkty[i] = losuj_punkt();
	}
	//punkty[0].x = 0.0;
	//punkty[0].y = -0.5;
	//punkty[1].x = 0.1;
	//punkty[1].y = -0.3;
	//punkty[2].x = 0.3;
	//punkty[2].y = 0.0;
	//punkty[3].x = 0.3;
	//punkty[3].y = 0.3;
	//punkty[4].x = 0.1;
	//punkty[4].y = 0.5;
	//punkty[5].x = 0.0;
	//punkty[5].y = 0.7;
	//punkty[6].x = -0.2;
	//punkty[6].y = 0.5;
	//punkty[7].x = -0.4;
	//punkty[7].y = 0.3;
	//punkty[8].x = -0.4;
	//punkty[8].y = 0.0;
	//punkty[9].x = -0.2;
	//punkty[9].y = -0.3;

	//WIELOKAT andrzej = WIELOKAT(10, punkty);

	//PUNKT badany_punkt = PUNKT(0.5, 0.5);
	//andrzej.czy_punkt_w_wielokacie(badany_punkt);
	
	//for (int i = 0; i < 10; i++) {
	//	andrzej.punkty[i].wypisz();
	//}
	//for (int i = 0; i < 10; i++) {
	//	cout << "\n\nkrawedz " << i;
	//	andrzej.krawedzie[i].wypisz();
	//}
	////andrzej.krawedzie[9].wypisz();
	//andrzej.punkty[9].wypisz();
	//andrzej.punkty[0].wypisz();

#pragma endregion

#pragma region otoczka
	WIELOKAT andrzej = WIELOKAT(10);
	andrzej = WIELOKAT::generuj_otoczke_z_chmury(punkty);


	//PUNKT test1(0.4, 0.4);
	//PUNKT test2;
	//test2 = test1;
	//test1.wypisz();
	//test2.wypisz();
	//test2=znajdz_najwyzszy_punkt_z_tablicy(punkty);
	//PUNKT badany_punkt = test2;
	//andrzej.czy_punkt_w_wielokacie(badany_punkt);
	//test2.wypisz();

#pragma endregion


	// Vertices coordinates
	//std::vector<GLdouble> vertices =
	GLfloat vertices[] =
	{
		//uk³ad wspó³rzêdnych
		ox.p1.x, ox.p1.y, 0.0,
		ox.p2.x, ox.p2.y, 0.0,
		oy.p1.x, oy.p1.y, 0.0,
		oy.p2.x, oy.p2.y, 0.0,
		//losowa prosta i losowy punkt
		//losowa_prosta.p1.x, losowa_prosta.p1.y, 0.0, //x prostej
		//losowa_prosta.p2.x, losowa_prosta.p2.y, 0.0, //y prostej 
		////trójk¹t
		//l1.p1.x, l1.p1.y, 0.0, //4
		//l1.p2.x, l1.p2.y, 0.0, //5
		//l2.p1.x, l2.p1.y, 0.0, //6
		//l2.p2.x, l2.p2.y, 0.0, //7
		//l3.p1.x, l3.p1.y, 0.0, //8
		//l3.p2.x, l3.p2.y, 0.0, //9

		andrzej.punkty[0].x,  andrzej.punkty[0].y, 0.0,//punkty wielokata
		andrzej.punkty[1].x,  andrzej.punkty[1].y, 0.0,
		andrzej.punkty[2].x,  andrzej.punkty[2].y, 0.0,
		andrzej.punkty[3].x,  andrzej.punkty[3].y, 0.0,
		andrzej.punkty[4].x,  andrzej.punkty[4].y, 0.0,
		andrzej.punkty[5].x,  andrzej.punkty[5].y, 0.0,
		andrzej.punkty[6].x,  andrzej.punkty[6].y, 0.0,
		andrzej.punkty[7].x,  andrzej.punkty[7].y, 0.0,
		andrzej.punkty[8].x,  andrzej.punkty[8].y, 0.0,
		andrzej.punkty[9].x,  andrzej.punkty[9].y, 0.0,
		//punkty[10].x, punkty[10].y, 0.0,
		//punkty[11].x, punkty[11].y, 0.0,
		//punkty[12].x, punkty[12].y, 0.0,
		//punkty[13].x, punkty[13].y, 0.0,
		//punkty[14].x, punkty[14].y, 0.0,
		//punkty[15].x, punkty[15].y, 0.0,
		//punkty[16].x, punkty[16].y, 0.0,
		//punkty[17].x, punkty[17].y, 0.0,
		//punkty[18].x, punkty[18].y, 0.0,
		//punkty[19].x, punkty[19].y, 0.0,

		//badany_punkt.x, badany_punkt.y, 0.0 //wspó³rzêdne szukanego punktu


		//input z tutoriala
		/*
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, //lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, //lower right corner
		0.0f, 0.5f * float(sqrt(3)) , 0.0f, //upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) * 2 / 6, 0.0f, //inner left
		0.5f / 2, 0.5f * float(sqrt(3)) * 2 / 6, 0.0f, //inner right
		0.0f, -0.5f * float(sqrt(3)) * 2 / 6, 0.0f //inner down
		*/
	};

	//for (int i = 0; i < 10; i++) {

	//	vertices.push_back(punkty[1].x);
	//	vertices.push_back(punkty[1].y);
	//	vertices.push_back(0.0);

	//}
	GLuint indices[] =
	{
		0, 1,//ox
		2, 3,//oy

		//4, 5,//losowa prosta
		//6//losowy punkt
		//trójk¹t
		//4,5,
		//6,7,
		//8,9,

		4,5,
		5,6,
		6,7,
		7,8,
		8,9,
		9,10,
		10,11,
		11,12,
		12,13,
		13,4,
		0,14,

		//14,15,
		//15,16,
		//16,17,
		//17,18,
		//18,19,
		//19,20,
		//20,21,
		//21,22,
		//22,23,
		//23,24,
		//24,4,

		//10//trójk¹t
		15//wielok¹t
		
		//0, 5, 5, 3, 3, 0, //lower left triangle
		//5, 1, 1, 4, 4, 5, //lower righttriangle
		//2, 3, 3, 4, 4, 2 //uppertriangle
	};

	
	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.linkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	// Specify the color of the background
	glClearColor(0.17f, 0.17f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);



	// Main while loop
	while (!glfwWindowShouldClose(window)) {

		// Specify the color of the background
		glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw the triangle using the GL_TRIANGLES primitive
		//glDrawElements(GL_LINE, 9, GL_UNSIGNED_INT, 0);
		
		//glDrawElements(GL_LINES, 12, GL_UNSIGNED_INT, 0);
		glDrawElements(GL_LINES, 26, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_POINTS, 11, 1);
		glDrawArrays(GL_POINTS, 15, 1);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);

		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	
	
	return 0;
}
