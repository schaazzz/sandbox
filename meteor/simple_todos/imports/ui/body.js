import { Meteor } from 'meteor/meteor';
import { Template } from 'meteor/templating';
import { ReactiveDict } from 'meteor/reactive-dict';
import { Tasks } from '../api/tasks.js';
import './task.js';
import './body.html';

Template.body.onCreated(function bodyOnCreated() {
    this.state = new ReactiveDict();
    Meteor.subscribe('tasks');
});

Template.body.helpers({
    title: {text: 'Simple Todos',
    incompleteCount() {
        return Tasks.find({checked: {$ne: true}}).count();
    }},
    tasks() {
        const instance = Template.instance();
        if (instance.state.get('hideCompleted')) {
            return Tasks.find({checked: {$ne: true}}, {sort: {createdAt: -1}});
        } else {
            return Tasks.find({}, {sort: {createdAt: -1}});
        }
    },
    hideCompleted: function () {
        return Session.get('hideCompleted');
    },
});

Template.body.events({
    'submit .new-task': function (event) {
        event.preventDefault();
        const target = event.target;
        const text = target.text.value;

        Meteor.call('tasks.insert', text);

        target.text.value = '';
    },
    'change .hide-completed input': function (event, instance) {
        instance.state.set('hideCompleted', event.target.checked);
    }
});
