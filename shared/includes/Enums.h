/*
** EPITECH PROJECT, 2018
** Enums.h
** File description:
** this enum represent the thread states
*/

#pragma once

#ifndef PLAZZA_ENUMS_H
#define PLAZZA_ENUMS_H

//! States the cause if thread completion
enum CompletionCause
{
    CookingTerminated,
    ErrorOccured,
    InactiveKitchen
};

#endif //PLAZZA_ENUMS_H

