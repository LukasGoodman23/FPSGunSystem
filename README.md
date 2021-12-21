# FPSGunSystem
 Repo for a project that emulates a popular first person gun system

This is a recreation of the gun system used by multiple popular fps game franchises. A lot of research went into making this as accurate as possible.

This fps system uses a cone based firing model. This means that all weapons have a cone that comes out of the barrel and the vector on which the gun will fire will exist
somewhere within that cone.

This fps also uses an aim assist system on all weapons that are capable of hitscan. The way this system works is that is uses a cone system to translate the firing cone
in such a way that more of the cone will line on the target, thus increasing the likelihood that a hit is registered.