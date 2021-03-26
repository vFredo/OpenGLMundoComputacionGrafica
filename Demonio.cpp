#include "Demonio.h"

Demonio::Demonio() {
	objmodel_ptr = NULL;

	if (!objmodel_ptr) {
		objmodel_ptr = glmReadOBJ("./Mallas/demonio.obj");
		if (!objmodel_ptr)
			exit(0);
		glmUnitize(objmodel_ptr);
		glmFacetNormals(objmodel_ptr);
		glmVertexNormals(objmodel_ptr, 90.0);
	}
}

void Demonio::DibujarObjeto() {
	glPushMatrix();

	glTranslatef(20, 0, -15);
	glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL);

	glPopMatrix();
}

Demonio::~Demonio() {
	objmodel_ptr = NULL;
}