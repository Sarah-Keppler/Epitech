'use strict'

/*
|--------------------------------------------------------------------------
| Routes
|--------------------------------------------------------------------------
|
| Http routes are entry points to your web application. You can create
| routes for different URLs and bind Controller actions to them.
|
| A complete guide on routing is available here.
| http://adonisjs.com/docs/4.1/routing
|
*/

/** @type {typeof import('@adonisjs/framework/src/Route/Manager')} */
const Route = use('Route')

Route.get('/auth/me', 'UserController.me').middleware(['auth'])
Route.post('auth/register', "UserController.register");
Route.post('auth/login', "UserController.login");
Route.post('auth/logout', "UserController.logout").middleware(['auth']);

Route.get('instance/all', "InstanceController.all").middleware('auth');
Route.get('instance', "InstanceController.list").middleware('auth');
Route.post('instance', "InstanceController.create").middleware('auth');
Route.delete('instance/:id', "InstanceController.delete").middleware('auth');
Route.patch('instance/:id', "InstanceController.update").middleware('auth');
Route.get('instance/refresh/:id', "InstanceController.refresh").middleware('auth');

Route.get('/about.json', 'InstanceController.about')