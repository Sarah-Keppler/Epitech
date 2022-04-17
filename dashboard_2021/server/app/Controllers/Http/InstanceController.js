'use strict'

const Instance = use('App/Models/Instance');
const Authorize = use('App/Services/Authorization');
const Services = use('App/Services/Services');

class InstanceController {
    all() {
        return Services.about.server.services;
    }

    about() {
        return Services.about;
    }

    async list({ auth }) {
        const user = await auth.getUser();
        const instances = (await user.instances().fetch()).toJSON();

        instances.forEach(ins => {
            ins.params = JSON.parse(ins.params)
        });

        return instances;
    }

    async create({ auth, request }) {
        const user = await auth.getUser();
        const { service, widget, refresh, params } = request.all();
        const instance = new Instance();

        instance.fill({
            service,
            widget,
            refresh,
            params: JSON.stringify(params)
        });

        await user.instances().save(instance);

        instance.params = JSON.parse(instance.params)

        return instance;
    }

    async update({auth, request, params}) {
        const user = await auth.getUser();
        const instance = await Instance.find(params.id);
        const newInstance = request.all();

        Authorize.verifyPermission(instance, user);
        instance.params = JSON.stringify(newInstance.params)
        instance.refresh = newInstance.refresh

        await instance.save();

        instance.params = JSON.parse(instance.params)

        return instance;
    }

    async delete({ auth, params }) {
        const user = await auth.getUser();
        const instance = await Instance.find(params.id);

        Authorize.verifyPermission(instance, user);

        await instance.delete()

        return instance;
    }

    async refresh({ auth, params }) {
        const user = await auth.getUser();
        const instance = await Instance.find(params.id);

        Authorize.verifyPermission(instance, user);

        instance.params = JSON.parse(instance.params)

        return Services.serviceManagement(instance)//.toJSON()
        // return 
    }
}

module.exports = InstanceController
