// Tiny cross-platform audio stub
#ifndef AUDIO_H
#define AUDIO_H

// Replace Windows-specific PlaySound calls with this no-op.
// Hook up a real cross-platform audio backend later if desired.
inline void playSound(const char* /*path*/) {
    // No-op: intentionally silent to keep code portable.
}

#endif // AUDIO_H

