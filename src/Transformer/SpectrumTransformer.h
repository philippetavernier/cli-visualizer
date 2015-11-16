/*
 * SpectrumTransformer.h
 *
 * Created on: Jul 30, 2015
 *     Author: dpayne
 */

#ifndef _SPECTRUM_TRANSFORMER_H
#define _SPECTRUM_TRANSFORMER_H

#include <fftw3.h>
#include "Transformer/GenericTransformer.h"
#include "Writer/NcursesWriter.h"
#include "Domain/Settings.h"

namespace vis
{

class SpectrumTransformer : public GenericTransformer
{
  public:
    explicit SpectrumTransformer(const Settings *const settings);

    ~SpectrumTransformer() override;

    void execute_mono(pcm_stereo_sample *buffer,
                              vis::NcursesWriter *writer) override;
    void execute_stereo(pcm_stereo_sample *buffer,
                                vis::NcursesWriter *writer) override;

  protected:
    void execute_fftw_plan(int32_t win_height);

    void draw_spectrum(int32_t win_height, int32_t win_width, bool flipped,
                       vis::NcursesWriter *writer);

  private:
    const Settings *const m_settings;
    size_t m_fftw_results;
    double *m_fftw_input;
    fftw_complex *m_fftw_output;
    fftw_plan m_fftw_plan;

    std::vector<double> m_freq_magnitudes;
    std::vector<double> m_freq_magnitudes_previous;
};
}

#endif
