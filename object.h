#pragma once
#include"camera.h"
#include"transform.h"
#include"mesh.h"
#include"shader.h"
#include"Ray.h"

static const int DISPLAY_WIDTH = 900;
static const int DISPLAY_HEIGHT = 600;
static glm::vec3 cameraPosition(2.0f, 5.0f, 5.0f);
//static glm::vec3 cameraPosition(-2.0f, -2.0f, -3.0f);
static Camera camera(/*glm::vec3(-2.0f, -2.0f, -3.0f)*//*glm::vec3(1.0f, 1.0f, -2.0f)*/cameraPosition, 70.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 0.01f, 100.0f);//position also is in function which return ray!

class Object {
public:
	//virtual void Draw() = 0;
	virtual void EditPosTransfrom(glm::vec3 pos) = 0;
	virtual void EditScaleTransform(glm::vec3 scale) = 0;
	virtual glm::mat4 GetModel() = 0;
	//virtual bool TriangleIntersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, Ray ray) = 0;
	virtual void SetAngleRotation(float angle) = 0;
	virtual void SetAxisRotation(glm::vec3 axis) = 0;
	virtual glm::vec3 GetObjectAxis() = 0;
	virtual void DrawStandart() = 0;
	virtual void ChangeColor(int) = 0;
};

class Pyramid : public Object {
private:
	Vertex Vertex1;
	Vertex Vertex2;
	Vertex Vertex3;
	Vertex Vertex4;
	Vertex Top;
	Vertex Base;
	Transform transform;
	glm::vec3 height;
	glm::vec4 colorSquare;
	glm::vec4 colorTriangle1;
	glm::vec4 colorTriangle2;
	glm::vec4 colorTriangle3;
	glm::vec4 colorTriangle4;
public:
	//Pyramid(Vertex Top, Vertex Base, Vertex Vertex1/*, glm::vec2 tex1Triangle, glm::vec2 tex2Triangle,
	//	glm::vec2 tex3Triangle, glm::vec2 tex4Triangle, glm::vec2 texSquare*/);
	////std::vector<Vertex> GetVertices() {
	////return vertices;
	////}
	////void SetVertices(std::vector<Vertex> vertices) {
	////this->vertices = vertices;
	////}
	Pyramid() {
		colorSquare = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);
		colorTriangle1 = glm::vec4(0.5, 0.0f, 0.0f, 1.0f);
		colorTriangle2 = glm::vec4(0.5, 0.0f, 0.0f, 1.0f);
		colorTriangle3 = glm::vec4(0.5, 0.0f, 0.0f, 1.0f);
		colorTriangle4 = glm::vec4(0.5, 0.0f, 0.0f, 1.0f);
	}
	void EditPosTransfrom(glm::vec3 pos) override {
		transform.EditPos(pos);
	}
	void EditScaleTransform(glm::vec3 scale) override {
		transform.EditScale(scale);
	}

	glm::mat4 GetModel() override{
		return transform.GetModel();
	}

	void SetAngleRotation(float angle) override{
		transform.SetRotAngle(angle);
	}

	void SetAxisRotation(glm::vec3 axis) override{
		transform.SetRotAxis(axis);
	}
	glm::vec3 GetObjectAxis() override;
//	Pyramid(){}
	void DrawStandart() override;
	void ChangeColor(int) override;
};

class Cone : public Object {
private:
	float radiusBottom;
	float radiusTop;
	glm::vec3 posBottomCenter;
	glm::vec3 posTopCenter;
	glm::vec4 colorTop;
	glm::vec4 colorBottom;
	glm::vec4 colorBody;
	Transform transform;
	glm::vec3 height;
//	std::vector<unsigned int> indicesTopCircle;
//	std::vector<unsigned int> indicesBottomCircle;
//	std::vector<unsigned int> indicesBody;
//	std::vector<Vertex> vertices;
	float delta;
public:
	/*Cone(float radiusBottom, float radiusTop, glm::vec3 posBottomCenter, glm::vec3 posTopCenter);*/
	void EditPosTransfrom(glm::vec3 pos) override {
		transform.EditPos(pos);
	}
	void EditScaleTransform(glm::vec3 scale) override {
		transform.EditScale(scale);
	}
	void SetAngleRotation(float angle) override{
		transform.SetRotAngle(angle);
	}

	void SetAxisRotation(glm::vec3 axis) override{
		transform.SetRotAxis(axis);
	}
	//glm::vec3 GetMinBox() override{
	//	return this->minBox;
	//}
	//glm::vec3 GetMaxBox() override{
	//	return this->maxBox;
	//}

	glm::vec3 GetObjectAxis() override;

	glm::mat4 GetModel() override{
		return transform.GetModel();
	}
	/*void FindVerticesCone(std::vector<Vertex>& vertices, std::vector<unsigned int>& indicesBottomCircle, std::vector<unsigned int>& indicesTopCircle,
		std::vector<unsigned int>& indicesBody);
	void Draw() override;
	bool TriangleIntersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, Ray ray) override;*/
	Cone(float delta) {
		this->delta = delta;
		colorTop = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);
		colorBottom = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);
		colorBody = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);
	}

	void SetColorTop(glm::vec4 colorTop) {
		this->colorTop = colorTop;
	}

	void SetColorBottom(glm::vec4 colorBottom) {
		this->colorBottom = colorBottom;
	}

	void SetColorBody(glm::vec4 colorBody) {
		this->colorBody = colorBody;
	}

	glm::vec4 GetColorTop() {
		return colorTop;
	}

	glm::vec4 GetColorBottom() {
		return colorBottom;
	}

	glm::vec4 GetColorBody() {
		return colorBody;
	}

	void DrawStandart() override;

	void ChangeColor(int) override;
};