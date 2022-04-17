const AppException = use('App/Exceptions/AppException')

class Authorization {
  verifyPermission(resource, user) {
    if (!resource) {
      throw new AppException("Invalid resource");
    } else if (resource.user_id !== user.id) {
      throw new AppException("Invalid access");
    }
  }
}

module.exports = new Authorization();