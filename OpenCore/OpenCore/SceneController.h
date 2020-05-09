#pragma once
#include "Model.h"
//#include "FireWork.h"
#include "AnimationModel.h"
#include "Camera.h"


class Scene {
public:

	Scene(float time);

	~Scene();

	void render(glm::mat4 model, glm::mat4& view, glm::mat4& projection,
		Camera::Camera& camera, float deltaTime, float timeflow);

	

private:

	
	Model* castle;
	Model* fountainPool;
	Model* waterPool;
	Model* fireheap;
	
	/*FireWork::FireWork *fireWork;*/
	
	AnimationModel* bat;
	/*Debug *debug;*/

	Shader* castleShader;
	Shader* batShader;
	Shader* shadowShader;

	GLuint depthMapFBO, depthMap;
	glm::mat4 lightSpaceMatrix1;
	glm::mat4 lightSpaceMatrix2;

	void OutsideRender(glm::mat4 model, glm::mat4& view, glm::mat4& projection,
		Camera::Camera& camera, float deltaTime, float& timeflow);

	void OutsideRenderShadow(glm::mat4 model, Camera::Camera& camera, float deltaTime, float& timeflow);

	void GenDepthTex();
};