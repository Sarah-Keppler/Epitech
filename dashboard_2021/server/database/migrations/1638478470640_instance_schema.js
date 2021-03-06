'use strict'

/** @type {import('@adonisjs/lucid/src/Schema')} */
const Schema = use('Schema')

class InstanceSchema extends Schema {
  up () {
    this.create('instances', (table) => {
      table.increments()
      table.integer('user_id').unsigned().references('id').inTable('users')
      table.string('service', 80).notNullable()
      table.string('widget', 80).notNullable()
      table.json('params').notNullable()
      table.integer('refresh').unsigned().notNullable()
      table.timestamps()
    })
  }

  down () {
    this.drop('instances')
  }
}

module.exports = InstanceSchema
