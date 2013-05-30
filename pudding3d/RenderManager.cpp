
#include "RenderManager.h"
#include "Renderer.h"
#include "Camera.h"
#include "Viewport.h"
#include "RenderList.h"

#include "Mesh.h"

RenderManager::RenderManager( Camera* camera, Viewport* viewport )
	:_camera(camera), _viewport(viewport)
{
	_renderer = new Renderer( viewport->_width, viewport->_height );

	_renderList = new RenderList;

	mesh = new Mesh;
	mesh->create("resource\\mymesh.txt");
}

RenderManager::~RenderManager()
{
	if( _renderer )
		delete _renderer;

	if( _renderList )
		delete _renderList;

	if( mesh )
		delete mesh;
}

void RenderManager::RenderFrame()
{
	_renderList->triangles().clear();
	for( auto& t : mesh->GetTriangles() )
	{
		_renderList->append( t );
	}


	_renderer->Begin();

	_camera->WorldToCamera( _renderList );
	_camera->CameraToScreen( _renderList, _viewport );
	
	_renderer->Render( _renderList );

	_renderer->End( _viewport );

	if( GetAsyncKeyState('W') & 0x0001 )
	{
		Vector3 pos = _camera->GetPosition();
		pos.Set( pos.x, pos.y + 1, pos.z );
		_camera->SetPosition( pos );
	}
	else if( GetAsyncKeyState('A') & 0x0001 )
	{
		Vector3 pos = _camera->GetPosition();
		pos.Set( pos.x - 1, pos.y, pos.z );
		_camera->SetPosition( pos );
	}
	else if( GetAsyncKeyState('S') & 0x0001 )
	{
		Vector3 pos = _camera->GetPosition();
		pos.Set( pos.x, pos.y - 1, pos.z );
		_camera->SetPosition( pos );
	}
	else if( GetAsyncKeyState('D') & 0x0001 )
	{
		Vector3 pos = _camera->GetPosition();
		pos.Set( pos.x + 1, pos.y, pos.z );
		_camera->SetPosition( pos );
	}
	if( GetAsyncKeyState('Z') & 0x0001 )
	{
		Vector3 pos = _camera->GetPosition();
		pos.Set( pos.x, pos.y, pos.z + 1 );
		_camera->SetPosition( pos );
	}
	if( GetAsyncKeyState('X') & 0x0001 )
	{
		Vector3 pos = _camera->GetPosition();
		pos.Set( pos.x, pos.y, pos.z - 1 );
		_camera->SetPosition( pos );
	}
}