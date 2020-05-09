#pragma once
#include "shader.h"
#include "texture.h"
#include "common.h"
#include <vector>

class Terrain
{
public:
	Terrain(string path);
	~Terrain();

	void LoadHeighmap(string& path);
	inline float GetTrueHeight(int i, int j);
	inline float GetHeight(float i, float j);
	void render(glm::mat4 model, glm::mat4 view, glm::mat4 projection, GLuint& depthMap);
	void renderShadow(Shader* shadowShader);
	void GenerateTerrain();
	float Travel(float i, float j);
	void setLightSpace(glm::mat4& lightSpace);

private:

	unsigned char* HeightData;
	int width, height, nrComponents, numVertex;
	float scale;
	GLuint terrainVBO, terrainVAO, terrainEBO;
	Shader* terrainShader;
	Shader* shader;
	// Texture stage 0 is used for the lowest points of the terrain while texture stage 2 is used for the highest points in the terrain.  
	// Texture stage 1 is blended between these two elevations depending on the blending method used 
	CTexture terrainTex[3];
	CTexture Normal;
	inline int GetIndex(int i, int j);
};
