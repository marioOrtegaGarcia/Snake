#include "App.h"

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
    
    // Instantiate a new App
    App* myApp = new App("Snake: Leonidas Edition", 50, 50, 1200, 1200);

	// Start the app
    myApp->run();
}
