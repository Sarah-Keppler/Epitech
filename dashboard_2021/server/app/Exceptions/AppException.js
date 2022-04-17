'use strict'

const { LogicalException } = require('@adonisjs/generic-exceptions')

class AppException extends LogicalException {
  /**
   * Handle this exception by itself
   */
  handle(error, {response}) {
    return response.status(500).json({error: error.message})
  }
}

module.exports = AppException
