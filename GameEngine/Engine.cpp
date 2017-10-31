#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Simple Game Engine",
		Style::Default);
	m_BackgroundTexture.loadFromFile("background.png");
	// Associate the sprite with the texture
	m_Bob.texture.loadFromFile("sonic_walk.png");
	m_Bob.setTexture();
	m_Bob.setTextureRect(0,0,102,110);
	m_Bob.setPosition2f(cam_position,m_Bob.position);
	//Texture *tex = new Texture();
	//tex->loadFromFile("ground.jpg");
	//plane1.texture.loadFromFile("ground.jpg");
	//plane1.setTexture();;
	//m_Bob.onGravity();
	//m_Bob.setVelocity(Vector2f(500, 0));
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// resize it to 5 points
	convex.setPointCount(3);

	// define the points
	convex.setPoint(0, sf::Vector2f(0, 0));
	convex.setPoint(1, sf::Vector2f(150, 10));
	convex.setPoint(2, sf::Vector2f(120, 90));
	/*convex.setPoint(3, sf::Vector2f(30, 100));
	convex.setPoint(4, sf::Vector2f(0, 50));*/
	convex.setPosition(Vector2f(1200,790));
}
void Engine::start()
{
	ifstream file("GameObjects.csv");
	string line;
	Circle *cobj;Plane *pobj;Psprite *sobj;ConvexPolygon *cpobj;
	bool skipfirstline = true;
	while (getline(file, line)) {
		if (skipfirstline) {
			skipfirstline = false;
			continue;
		}
		stringstream strstr(line);
		string word = "";
		int arr[30];
		int arr_pos = 0;
		string texfile;
		object* obj;
		//int flagobj = -1;
		while (getline(strstr, word, ',')) {
			//cout << arr_pos << "	" << word << endl;
			if (arr_pos == 0) {
				if (word == "Circle") {
					arr[arr_pos] = 0;
				}
				else if (word == "Plane") {
					arr[arr_pos] = 1;
				}
				else if (word == "Psrite") {
					arr[arr_pos] = 2;
				}
				else if (word == "Convex") {
					arr[arr_pos] = 3;
				}
				else {
					arr[arr_pos] = 100;
				}
			}
			else if (arr_pos == 10) {
				texfile = word;
			}
			else {
				stringstream value(word);
				int val = 0;
				value >> val;
				arr[arr_pos] = val;
			}
			arr_pos++;
		}
		/*for (int i = 0; i < 16;i++) {
			cout << i << "  " << arr[i] << endl;
		}*/
		if (arr[0] == 0) {
			cout << "Found a circle" << endl;
			vobj.push_back(0);
			int sides = arr[16];
			cobj = new Circle(Position2f(arr[1], arr[2]), arr[3], Vector2f(arr[4], arr[5]), arr[6],Vector2f(arr[11],arr[12]), Vector2f(arr[13], arr[14]),sides);
			cout << arr[11] << "	" << arr[12] << endl;
			cobj->onGravity();
			cobj->setColor(arr[7], arr[8], arr[9]);
			if (texfile != "") {
				cobj->texture.loadFromFile(texfile);
				cobj->setTexture();
			}
			obj = cobj;
			vec.push_back(obj);
		}
		else if (arr[0] == 1) {
			cout << "Found a Rect" << endl;
			vobj.push_back(1);cout << arr[3] << endl;
			pobj = new Plane(Position2f(arr[1], arr[2]), arr[3], Vector2f(arr[4], arr[5]), arr[6], Vector2f(arr[11], arr[12]), Vector2f(arr[13], arr[14]));
			pobj->setColor(arr[7], arr[8], arr[9]);
			//cobj->onGravity();
			if (texfile != "") {
				pobj->texture.loadFromFile(texfile);
				pobj->setTexture();
			}
			obj = pobj;
			if (arr[15] == 1)	obj->moveFlag = 1;
			vec.push_back(obj);
			//cout << obj.position.pos.x << endl;
		}
		else if (arr[0] == 2) {
			cout << "Found a sprite" << endl;
			vobj.push_back(2);
			sobj = new Psprite(Position2f(arr[1], arr[2]), arr[3], Vector2f(arr[4], arr[5]), arr[6], Vector2f(arr[11], arr[12]), Vector2f(arr[13], arr[14]));
			//sobj->setVelocity(Vector2f(arr[11], arr[12]));
			//sobj->setAcceleration(Vector2f(arr[13], arr[14]));
			sobj->setColor(arr[7], arr[8], arr[9]);
			if (texfile != "") {
				sobj->texture.loadFromFile(texfile);
				sobj->setTexture();
			}
			obj = sobj;
			if (arr[15] == 1)	obj->moveFlag = 1;
			vec.push_back(obj);
		}
		else if (arr[0] == 3) {
			vobj.push_back(3);
			int sides = arr[16];
			vector<Vector2f> v;
			int edge_pos = 17;
			for (int i = 0; i < sides; i++) {
				//cout << arr[edge_pos] << "	" << arr[edge_pos + 1] << "	nodes" << endl;
				v.push_back(Vector2f(arr[edge_pos],arr[edge_pos+1]));
				edge_pos += 2;
			}//cpobj = new ConvexPolygon();
			cpobj = new ConvexPolygon(Position2f(arr[1],arr[2]),v,sides,arr[2],arr[5],Vector2f(arr[11],arr[12]), Vector2f(arr[13], arr[14]));
			if (texfile != "") {
				cpobj->texture.loadFromFile(texfile);
				cpobj->setTexture();
			}
			obj = cpobj;
			if (arr[15] == 1)	obj->moveFlag = 1;
			vec.push_back(obj);
		}
		else {
			vobj.push_back(100);
			cout << "No such Shape" << endl;
		}
	}
	// Timing
	Clock clock;

	while (m_Window.isOpen())
	{
		//cout << plane1.position.pos.x << endl;
		// Restart the clock and save the elapsed time into dt
		Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();
		cout <<"fps:" <<  1/dtAsSeconds << endl;
		input();
		update(dtAsSeconds);
		draw();
	}
}
void Engine::LeftPressed() {
	moveLeft = true;
}
void Engine::RightPressed() {
	moveRight = true;
}
void Engine::stopLeft() {
	moveLeft = false;
}
void Engine::stopRight() {
	moveRight = false;
}
void Engine::input() {
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		m_Window.close();
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		m_Bob.LeftPressed();
		LeftPressed();
		
	}
	else{
		m_Bob.stopLeft();
		stopLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		m_Bob.counter++;
		m_Bob.RightPressed();
		RightPressed();
	}
	else {
		m_Bob.counter = 0;
		m_Bob.stopRight();
		stopRight();
	}
	if (m_Bob.counter > 100) {
		m_Bob.counter = 20;
	}
}
void Engine::update(float interval) {
	//update player position everyframe
	m_Bob.Update(interval);
	//move the camera
	
	for (int i = 0; i < vec.size();i++) {
		if (vec[i]->moveFlag == 1) {
			if (vec[i]->position.pos.x - cam_position.pos.x - vec[i]->Scale.x  < 1100 && vec[i]->position.pos.x - cam_position.pos.x + vec[i]->Scale.x > -1100) {
				if (vec[i]->position.pos.y - cam_position.pos.y - vec[i]->Scale.y < 600 && vec[i]->position.pos.y - cam_position.pos.y + vec[i]->Scale.y > -600) {
					vec[i]->Update(interval);
					}
				}
			}
		else {
			vec[i]->Update(interval);
		}
	}
	if(moveLeft)
		cam_position.movePos(-cam_speed*interval,0);
	if (moveRight)
		cam_position.movePos(cam_speed*interval,0);
}
void Engine::draw() {
	m_Window.clear(Color::White);
	m_Bob.setPosition2f(cam_position, m_Bob.position);
	//hud.setPosition(960,270);
	for (int i = 0; i < vec.size();i++) {
		vec[i]->setPosition2f(cam_position, vec[i]->position);
	}
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Bob.getSprite());
	//m_Window.draw(convex);
	for (int i = 0; i < vec.size();i++) {
		if (vobj[i] == 0) {
			if (vec[i]->position.pos.x - cam_position.pos.x - vec[i]->Scale.x  < 1100 && vec[i]->position.pos.x - cam_position.pos.x + vec[i]->Scale.x > -1100) {
				if (vec[i]->position.pos.y - cam_position.pos.y - vec[i]->Scale.y < 600 && vec[i]->position.pos.y - cam_position.pos.y + vec[i]->Scale.y > -600) {
					m_Window.draw(vec[i]->getCircleShape());
					cout << "Drawing circle at " << i << "th column." << endl;
				}
			}	
		}
		else if (vobj[i] == 1) {
			//cout << "Drawing" << endl;
			if (vec[i]->position.pos.x - cam_position.pos.x - vec[i]->Scale.x < 1100 && vec[i]->position.pos.x - cam_position.pos.x + vec[i]->Scale.x > -1100) {
				if (vec[i]->position.pos.y - cam_position.pos.y - vec[i]->Scale.y < 600 && vec[i]->position.pos.y - cam_position.pos.y + vec[i]->Scale.y > -600) {
					m_Window.draw(vec[i]->getRectShape());
					cout << "Drawing plane at " << i << "th column." << endl;
				}
			}
			
		}
		else if (vobj[i] == 2) {
			m_Window.draw(vec[i]->getSprite());
			cout << "Drawing sprite at " << i << "th column." << endl;
		}
		else if (vobj[i] == 3) {
			if (vec[i]->position.pos.x - cam_position.pos.x - vec[i]->Scale.x  < 1100 && vec[i]->position.pos.x - cam_position.pos.x + vec[i]->Scale.x > -1100) {
				if (vec[i]->position.pos.y - cam_position.pos.y - vec[i]->Scale.y < 600 && vec[i]->position.pos.y - cam_position.pos.y + vec[i]->Scale.y > -600) {
					m_Window.draw(vec[i]->getConvexShape());
					cout << "Drawing Convex at " << i << "th column." << endl;
				}
			}
		}
		else {
			cout << "No object exists to draw." << endl;
		}
	}
	m_Window.display();
	
}
