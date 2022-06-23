#pragma once
#include<string>
class image
{
public:
	image() = default;
	virtual bool loadImage(std::string filePath) = 0;
	int getWidth() { return width; }
	int getHeight() { return height; }
	std::string getFilePath() { return filePath; }
	std::string getFileName() { return fileName; }
	virtual ~image() = default;
private:

protected:
	int width, height;
	std::string filePath;
	std::string fileName;
	char* _data;
};

class imageGif :public image
{
public:
	virtual bool loadImage(std::string filePath) override{
		return true;
	}
};

class imageTiff :public image
{
public:
	virtual bool loadImage(std::string filePath) override {
		return true;
	}
};

class imageJpeg :public image
{
public:
	virtual bool loadImage(std::string filePath) override {
		return true;
	}
};

class imageBmp :public image
{
public:
	virtual bool loadImage(std::string filePath) override {
		return true;
	}
};