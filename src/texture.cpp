#include "texture.h"
#include "CGL/color.h"

#include <cmath>
#include <algorithm>

namespace CGL {

Color Texture::sample(const SampleParams &sp) {
  // Parts 5 and 6: Fill this in.
  // Should return a color sampled based on the psm and lsm parameters given
//  float u = (float) sp.p_uv[0] * width;
//  float v = (float) sp.p_uv[1] * height;
//  if (sp.psm == P_NEAREST) {
//    Vector2D nearest = Vector2D(floor(u), floor(v));
//    unsigned char red = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)];
//    unsigned char green = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)+1];
//    unsigned char blue = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)+2];
//    Color final;
//    final.r = (float) red / 255;
//    final.g = (float) green / 255;
//    final.b = (float) blue / 255;
//    return final;
//  }
//  //Bilinear
//  float diff_u = u - floor(u);
//  float diff_v = v - floor(v);
//  float base_u;
//  float base_v;
//  if (diff_u <= 0.5) {
//    base_u = floor(u);
//  }
//  if (diff_u > 0.5) {
//    base_u = floor(u);
//  }
//  if (diff_v <= 0.5) {
//    base_v = floor(v);
//  }
//  if (diff_v > 0.5) {
//    base_v = floor(v);
//  }
//
//  double s = u - (base_u - 0.5);
//  double t = (base_v+0.5) - v;
//
//  Color final;
//
//  unsigned char red00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)];
//  unsigned char green00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)+1];
//  unsigned char blue00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)+2];
//
//  unsigned char red10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)];
//  unsigned char green10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)+1];
//  unsigned char blue10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)+2];
//
//  unsigned char red01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)];
//  unsigned char green01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)+1];
//  unsigned char blue01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)+2];
//
//  unsigned char red11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)];
//  unsigned char green11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)+1];
//  unsigned char blue11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)+2];
//
//  unsigned char red0 = red00 + (unsigned char)s * (red10 - red00);
//  unsigned char green0 = green00 + (unsigned char)s * (green10 - green00);
//  unsigned char blue0 = blue00 + (unsigned char)s * (blue10 - blue00);
//
//  unsigned char red1 = red01 + (unsigned char)s * (red11 - red01);
//  unsigned char green1 = green01 + (unsigned char)s * (green11 - green01);
//  unsigned char blue1 = blue01 + (unsigned char)s * (blue11 - blue01);
//
//  unsigned char finalred = red0 + (unsigned char)t * (red1 - red0);
//  unsigned char finalgreen = green0 + (unsigned char)t * (green1 - green0);
//  unsigned char finalblue = blue0 + (unsigned char)t * (blue1 - blue0);
//
//  final.r = (float) finalred / 255;
//  final.g = (float) finalgreen / 255;
//  final.b = (float) finalblue / 255;
//  return final;


//PART 6
  // Level 0
  if (sp.lsm == L_ZERO) {
    float u = (float) sp.p_uv[0] * width;
    float v = (float) sp.p_uv[1] * height;
    if (sp.psm == P_NEAREST) {
      Vector2D nearest = Vector2D(floor(u), floor(v));
      unsigned char red = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)];
      unsigned char green = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)+1];
      unsigned char blue = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)+2];
      Color final;
      final.r = (float) red / 255;
      final.g = (float) green / 255;
      final.b = (float) blue / 255;
      return final;
    }
    //Bilinear
    float diff_u = u - floor(u);
    float diff_v = v - floor(v);
    float base_u;
    float base_v;
    if (diff_u <= 0.5) {
      base_u = floor(u);
    }
    if (diff_u > 0.5) {
      base_u = floor(u);
    }
    if (diff_v <= 0.5) {
      base_v = floor(v);
    }
    if (diff_v > 0.5) {
      base_v = floor(v);
    }

    double s = u - (base_u - 0.5);
    double t = (base_v+0.5) - v;

    Color final;

    unsigned char red00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)];
    unsigned char green00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)+1];
    unsigned char blue00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)+2];

    unsigned char red10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)];
    unsigned char green10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)+1];
    unsigned char blue10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)+2];

    unsigned char red01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)];
    unsigned char green01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)+1];
    unsigned char blue01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)+2];

    unsigned char red11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)];
    unsigned char green11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)+1];
    unsigned char blue11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)+2];

    unsigned char red0 = red00 + (unsigned char)s * (red10 - red00);
    unsigned char green0 = green00 + (unsigned char)s * (green10 - green00);
    unsigned char blue0 = blue00 + (unsigned char)s * (blue10 - blue00);

    unsigned char red1 = red01 + (unsigned char)s * (red11 - red01);
    unsigned char green1 = green01 + (unsigned char)s * (green11 - green01);
    unsigned char blue1 = blue01 + (unsigned char)s * (blue11 - blue01);

    unsigned char finalred = red0 + (unsigned char)t * (red1 - red0);
    unsigned char finalgreen = green0 + (unsigned char)t * (green1 - green0);
    unsigned char finalblue = blue0 + (unsigned char)t * (blue1 - blue0);

    final.r = (float) finalred / 255;
    final.g = (float) finalgreen / 255;
    final.b = (float) finalblue / 255;
    return final;
  }

  //Nearest Level
  if (sp.lsm == L_NEAREST) {


    float u00 = (float) sp.p_uv[0]*width;
    float v00 = (float) sp.p_uv[1]*height;

    float u10 = (float) sp.p_dx_uv[0]*width;
    float v10 = (float) sp.p_dx_uv[1]*height;

    float u01 = (float) sp.p_dy_uv[0]*width;
    float v01 = (float) sp.p_dy_uv[1]*height;

    float du_dx = u10 - u00;
    float dv_dx = v10 - v00;
    float du_dy = u01 - u00;
    float dv_dy = v01 - v00;

    float L = max(sqrt((du_dx*du_dx)+(dv_dx*dv_dx)),sqrt((du_dy*du_dy)+(dv_dy*dv_dy)));

    //L = ceil(L);
    float level = (float)(log(L) / log(2));
    if (level<1) {
        level=1;
    }
    if (level>mipmap.size()) {
        level=mipmap.size()-1;
    }
    int nearest_level;



    if (level - floor(level) < 0.5) {
       nearest_level = (int)floor(level);
    }
    if (level - floor(level) >= 0.5) {
      nearest_level = (int)ceil(level);
    }


    float u = (float) sp.p_uv[0] * mipmap[nearest_level].width;
    float v = (float) sp.p_uv[1] * mipmap[nearest_level].height;

    if (sp.psm == P_NEAREST) {
      Vector2D nearest = Vector2D(floor(u), floor(v));

      unsigned char red = mipmap[nearest_level].texels[(int)((nearest[1]*mipmap[nearest_level].width+nearest[0])*3)];
      unsigned char green = mipmap[nearest_level].texels[(int)((nearest[1]*mipmap[nearest_level].width+nearest[0])*3)+1];
      unsigned char blue = mipmap[nearest_level].texels[(int)((nearest[1]*mipmap[nearest_level].width+nearest[0])*3)+2];
      Color final;
      final.r = (float) red / 255;
      final.g = (float) green / 255;
      final.b = (float) blue / 255;
      return final;
    }
    //Bilinear
    float diff_u = u - floor(u);
    float diff_v = v - floor(v);
    float base_u;
    float base_v;
    if (diff_u <= 0.5) {
      base_u = floor(u);
    }
    if (diff_u > 0.5) {
      base_u = floor(u);
    }
    if (diff_v <= 0.5) {
      base_v = floor(v);
    }
    if (diff_v > 0.5) {
      base_v = floor(v);
    }

    double s = u - (base_u - 0.5);
    double t = (base_v+0.5) - v;

    Color final;

    unsigned char red00 = mipmap[nearest_level].texels[(int)((base_v*mipmap[nearest_level].width+(base_u-1))*3)];
    unsigned char green00 = mipmap[nearest_level].texels[(int)((base_v*mipmap[nearest_level].width+(base_u-1))*3)+1];
    unsigned char blue00 = mipmap[nearest_level].texels[(int)((base_v*mipmap[nearest_level].width+(base_u-1))*3)+2];

    unsigned char red10 = mipmap[nearest_level].texels[(int)((base_v*mipmap[nearest_level].width+(base_u))*3)];
    unsigned char green10 = mipmap[nearest_level].texels[(int)((base_v*mipmap[nearest_level].width+(base_u))*3)+1];
    unsigned char blue10 = mipmap[nearest_level].texels[(int)((base_v*mipmap[nearest_level].width+(base_u))*3)+2];

    unsigned char red01 = mipmap[nearest_level].texels[(int)(((base_v-1)*mipmap[nearest_level].width+(base_u-1))*3)];
    unsigned char green01 = mipmap[nearest_level].texels[(int)(((base_v-1)*mipmap[nearest_level].width+(base_u-1))*3)+1];
    unsigned char blue01 = mipmap[nearest_level].texels[(int)(((base_v-1)*mipmap[nearest_level].width+(base_u-1))*3)+2];

    unsigned char red11 = mipmap[nearest_level].texels[(int)(((base_v-1)*mipmap[nearest_level].width+(base_u))*3)];
    unsigned char green11 = mipmap[nearest_level].texels[(int)(((base_v-1)*mipmap[nearest_level].width+(base_u))*3)+1];
    unsigned char blue11 = mipmap[nearest_level].texels[(int)(((base_v-1)*mipmap[nearest_level].width+(base_u))*3)+2];

    unsigned char red0 = red00 + (unsigned char)s * (red10 - red00);
    unsigned char green0 = green00 + (unsigned char)s * (green10 - green00);
    unsigned char blue0 = blue00 + (unsigned char)s * (blue10 - blue00);

    unsigned char red1 = red01 + (unsigned char)s * (red11 - red01);
    unsigned char green1 = green01 + (unsigned char)s * (green11 - green01);
    unsigned char blue1 = blue01 + (unsigned char)s * (blue11 - blue01);

    unsigned char finalred = red0 + (unsigned char)t * (red1 - red0);
    unsigned char finalgreen = green0 + (unsigned char)t * (green1 - green0);
    unsigned char finalblue = blue0 + (unsigned char)t * (blue1 - blue0);

    final.r = (float) finalred / 255;
    final.g = (float) finalgreen / 255;
    final.b = (float) finalblue / 255;
    return final;

  }
  // Average Color
  else {
      float u00 = (float) sp.p_uv[0]*width;
      float v00 = (float) sp.p_uv[1]*height;

      float u10 = (float) sp.p_dx_uv[0]*width;
      float v10 = (float) sp.p_dx_uv[1]*height;

      float u01 = (float) sp.p_dy_uv[0]*width;
      float v01 = (float) sp.p_dy_uv[1]*height;

      float du_dx = u10 - u00;
      float dv_dx = v10 - v00;
      float du_dy = u01 - u00;
      float dv_dy = v01 - v00;

      float L = max(sqrt((du_dx*du_dx)+(dv_dx*dv_dx)),sqrt((du_dy*du_dy)+(dv_dy*dv_dy)));

      //L = ceil(L);
      float level = (float)(log(L) / log(2));

      if (level<1) {
          level=1;
      }
      if (level>mipmap.size()) {
          level=mipmap.size()-1;
      }

      if (level == 1 or level == mipmap.size() - 1) {
          float u = (float) sp.p_uv[0] * width;
          float v = (float) sp.p_uv[1] * height;
          if (sp.psm == P_NEAREST) {
              Vector2D nearest = Vector2D(floor(u), floor(v));
              unsigned char red = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)];
              unsigned char green = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)+1];
              unsigned char blue = mipmap[0].texels[(int)((nearest[1]*width+nearest[0])*3)+2];
              Color final;
              final.r = (float) red / 255;
              final.g = (float) green / 255;
              final.b = (float) blue / 255;
              return final;
          }
          //Bilinear
          float diff_u = u - floor(u);
          float diff_v = v - floor(v);
          float base_u;
          float base_v;
          if (diff_u <= 0.5) {
              base_u = floor(u);
          }
          if (diff_u > 0.5) {
              base_u = floor(u);
          }
          if (diff_v <= 0.5) {
              base_v = floor(v);
          }
          if (diff_v > 0.5) {
              base_v = floor(v);
          }

          double s = u - (base_u - 0.5);
          double t = (base_v+0.5) - v;

          Color final;

          unsigned char red00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)];
          unsigned char green00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)+1];
          unsigned char blue00 = mipmap[0].texels[(int)((base_v*width+(base_u-1))*3)+2];

          unsigned char red10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)];
          unsigned char green10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)+1];
          unsigned char blue10 = mipmap[0].texels[(int)((base_v*width+(base_u))*3)+2];

          unsigned char red01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)];
          unsigned char green01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)+1];
          unsigned char blue01 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u-1))*3)+2];

          unsigned char red11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)];
          unsigned char green11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)+1];
          unsigned char blue11 = mipmap[0].texels[(int)(((base_v-1)*width+(base_u))*3)+2];

          unsigned char red0 = red00 + (unsigned char)s * (red10 - red00);
          unsigned char green0 = green00 + (unsigned char)s * (green10 - green00);
          unsigned char blue0 = blue00 + (unsigned char)s * (blue10 - blue00);

          unsigned char red1 = red01 + (unsigned char)s * (red11 - red01);
          unsigned char green1 = green01 + (unsigned char)s * (green11 - green01);
          unsigned char blue1 = blue01 + (unsigned char)s * (blue11 - blue01);

          unsigned char finalred = red0 + (unsigned char)t * (red1 - red0);
          unsigned char finalgreen = green0 + (unsigned char)t * (green1 - green0);
          unsigned char finalblue = blue0 + (unsigned char)t * (blue1 - blue0);

          final.r = (float) finalred / 255;
          final.g = (float) finalgreen / 255;
          final.b = (float) finalblue / 255;
          return final;

      }


      int lower_bound = (int)floor(level);
      int upper_bound = (int)ceil(level);
      float difference = level - (float)lower_bound;


      float u_lower = (float) sp.p_uv[0] * mipmap[lower_bound].width;
      float v_lower = (float) sp.p_uv[1] * mipmap[lower_bound].height;
      float u_upper = (float) sp.p_uv[0] * mipmap[upper_bound].width;
      float v_upper = (float) sp.p_uv[1] * mipmap[upper_bound].height;

      if (sp.psm == P_NEAREST) {
          Vector2D nearest_lower = Vector2D(floor(u_lower), floor(v_lower));
          Vector2D nearest_upper = Vector2D(floor(u_upper), floor(v_upper));

          unsigned char red_lower = mipmap[lower_bound].texels[(int)((nearest_lower[1]*mipmap[lower_bound].width+nearest_lower[0])*3)];
          unsigned char green_lower = mipmap[lower_bound].texels[(int)((nearest_lower[1]*mipmap[lower_bound].width+nearest_lower[0])*3)+1];
          unsigned char blue_lower = mipmap[lower_bound].texels[(int)((nearest_lower[1]*mipmap[lower_bound].width+nearest_lower[0])*3)+2];

          unsigned char red_upper = mipmap[upper_bound].texels[(int)((nearest_upper[1]*mipmap[upper_bound].width+nearest_upper[0])*3)];
          unsigned char green_upper = mipmap[upper_bound].texels[(int)((nearest_upper[1]*mipmap[upper_bound].width+nearest_upper[0])*3)+1];
          unsigned char blue_upper = mipmap[upper_bound].texels[(int)((nearest_upper[1]*mipmap[upper_bound].width+nearest_upper[0])*3)+2];

          unsigned char final_red = red_lower + (unsigned char)difference * (red_upper - red_lower);
          unsigned char final_green = green_lower + (unsigned char)difference * (green_upper - green_lower);
          unsigned char final_blue = blue_lower + (unsigned char)difference * (blue_upper - blue_lower);

          Color final;
          final.r = (float) final_red / 255;
          final.g = (float) final_green / 255;
          final.b = (float) final_blue / 255;
          return final;
      }
      //Bilinear

      double s_lower = u_lower - (floor(u_lower) - 0.5);
      double s_upper = u_upper - (floor(u_upper) - 0.5);

      double t_lower = (floor(v_lower)+0.5) - v_lower;
      double t_upper = (floor(v_upper)+0.5) - v_upper;

      Color final;

      unsigned char red00_lower = mipmap[lower_bound].texels[(int)((floor(v_lower)*mipmap[lower_bound].width+(floor(u_lower)-1))*3)];
      unsigned char green00_lower = mipmap[lower_bound].texels[(int)((floor(v_lower)*mipmap[lower_bound].width+(floor(u_lower)-1))*3)+1];
      unsigned char blue00_lower = mipmap[lower_bound].texels[(int)((floor(v_lower)*mipmap[lower_bound].width+(floor(u_lower)-1))*3)+2];

      unsigned char red10_lower = mipmap[lower_bound].texels[(int)((floor(v_lower)*mipmap[lower_bound].width+(floor(u_lower)))*3)];
      unsigned char green10_lower = mipmap[lower_bound].texels[(int)((floor(v_lower)*mipmap[lower_bound].width+(floor(u_lower)))*3)+1];
      unsigned char blue10_lower = mipmap[lower_bound].texels[(int)((floor(v_lower)*mipmap[lower_bound].width+(floor(u_lower)))*3)+2];

      unsigned char red01_lower = mipmap[lower_bound].texels[(int)(((floor(v_lower)-1)*mipmap[lower_bound].width+(floor(u_lower)-1))*3)];
      unsigned char green01_lower = mipmap[lower_bound].texels[(int)(((floor(v_lower)-1)*mipmap[lower_bound].width+(floor(u_lower)-1))*3)+1];
      unsigned char blue01_lower = mipmap[lower_bound].texels[(int)(((floor(v_lower)-1)*mipmap[lower_bound].width+(floor(u_lower)-1))*3)+2];

      unsigned char red11_lower = mipmap[lower_bound].texels[(int)(((floor(v_lower)-1)*mipmap[lower_bound].width+(floor(u_lower)))*3)];
      unsigned char green11_lower = mipmap[lower_bound].texels[(int)(((floor(v_lower)-1)*mipmap[lower_bound].width+(floor(u_lower)))*3)+1];
      unsigned char blue11_lower = mipmap[lower_bound].texels[(int)(((floor(v_lower)-1)*mipmap[lower_bound].width+(floor(u_lower)))*3)+2];

      unsigned char red0_lower = red00_lower + (unsigned char)s_lower * (red10_lower - red00_lower);
      unsigned char green0_lower = green00_lower + (unsigned char)s_lower * (green10_lower - green00_lower);
      unsigned char blue0_lower = blue00_lower + (unsigned char)s_lower * (blue10_lower - blue00_lower);

      unsigned char red1_lower = red01_lower + (unsigned char)s_lower * (red11_lower - red01_lower);
      unsigned char green1_lower = green01_lower + (unsigned char)s_lower * (green11_lower - green01_lower);
      unsigned char blue1_lower = blue01_lower + (unsigned char)s_lower * (blue11_lower - blue01_lower);

      unsigned char finalred_lower = red0_lower + (unsigned char)t_lower * (red1_lower - red0_lower);
      unsigned char finalgreen_lower = green0_lower + (unsigned char)t_lower * (green1_lower - green0_lower);
      unsigned char finalblue_lower = blue0_lower + (unsigned char)t_lower * (blue1_lower - blue0_lower);



      unsigned char red00_upper = mipmap[upper_bound].texels[(int)((floor(v_upper)*mipmap[upper_bound].width+(floor(u_upper)-1))*3)];
      unsigned char green00_upper = mipmap[upper_bound].texels[(int)((floor(v_upper)*mipmap[upper_bound].width+(floor(u_upper)-1))*3)+1];
      unsigned char blue00_upper = mipmap[upper_bound].texels[(int)((floor(v_upper)*mipmap[upper_bound].width+(floor(u_upper)-1))*3)+2];

      unsigned char red10_upper = mipmap[upper_bound].texels[(int)((floor(v_upper)*mipmap[upper_bound].width+(floor(u_upper)))*3)];
      unsigned char green10_upper = mipmap[upper_bound].texels[(int)((floor(v_upper)*mipmap[upper_bound].width+(floor(u_upper)))*3)+1];
      unsigned char blue10_upper = mipmap[upper_bound].texels[(int)((floor(v_upper)*mipmap[upper_bound].width+(floor(u_upper)))*3)+2];

      unsigned char red01_upper = mipmap[upper_bound].texels[(int)(((floor(v_upper)-1)*mipmap[upper_bound].width+(floor(u_upper)-1))*3)];
      unsigned char green01_upper = mipmap[upper_bound].texels[(int)(((floor(v_upper)-1)*mipmap[upper_bound].width+(floor(u_upper)-1))*3)+1];
      unsigned char blue01_upper = mipmap[upper_bound].texels[(int)(((floor(v_upper)-1)*mipmap[upper_bound].width+(floor(u_upper)-1))*3)+2];

      unsigned char red11_upper = mipmap[upper_bound].texels[(int)(((floor(v_upper)-1)*mipmap[upper_bound].width+(floor(u_upper)))*3)];
      unsigned char green11_upper = mipmap[upper_bound].texels[(int)(((floor(v_upper)-1)*mipmap[upper_bound].width+(floor(u_upper)))*3)+1];
      unsigned char blue11_upper = mipmap[upper_bound].texels[(int)(((floor(v_upper)-1)*mipmap[upper_bound].width+(floor(u_upper)))*3)+2];

      unsigned char red0_upper = red00_upper + (unsigned char)s_upper * (red10_upper - red00_upper);
      unsigned char green0_upper = green00_upper + (unsigned char)s_upper * (green10_upper - green00_upper);
      unsigned char blue0_upper = blue00_upper + (unsigned char)s_upper * (blue10_upper - blue00_upper);

      unsigned char red1_upper = red01_upper + (unsigned char)s_upper * (red11_upper - red01_upper);
      unsigned char green1_upper = green01_upper + (unsigned char)s_upper * (green11_upper - green01_upper);
      unsigned char blue1_upper = blue01_upper + (unsigned char)s_upper * (blue11_upper - blue01_upper);

      unsigned char finalred_upper = red0_upper + (unsigned char)t_upper * (red1_upper - red0_upper);
      unsigned char finalgreen_upper = green0_upper + (unsigned char)t_upper * (green1_upper - green0_upper);
      unsigned char finalblue_upper = blue0_upper + (unsigned char)t_upper * (blue1_upper - blue0_upper);


      unsigned char final_red = finalred_lower + (unsigned char)difference * (finalred_upper - finalred_lower);
      unsigned char final_green = finalgreen_lower + (unsigned char)difference * (finalgreen_upper - finalgreen_lower);
      unsigned char final_blue = finalblue_lower + (unsigned char)difference * (finalblue_upper - finalblue_lower);

      final.r = (float) final_red / 255;
      final.g = (float) final_green / 255;
      final.b = (float) final_blue / 255;
      return final;
  }

}

float Texture::get_level(const SampleParams &sp) {
  // Optional helper function for Parts 5 and 6
  return 0;
}

// Returns the nearest sample given a particular level and set of uv coords
Color Texture::sample_nearest(Vector2D uv, int level) {
  // Optional helper function for Parts 5 and 6
  // Feel free to ignore or create your own
  return Color();
}

// Returns the bilinear sample given a particular level and set of uv coords
Color Texture::sample_bilinear(Vector2D uv, int level) {
  // Optional helper function for Parts 5 and 6
  // Feel free to ignore or create your own
  return Color();
}



/****************************************************************************/



inline void uint8_to_float(float dst[3], unsigned char *src) {
  uint8_t *src_uint8 = (uint8_t *)src;
  dst[0] = src_uint8[0] / 255.f;
  dst[1] = src_uint8[1] / 255.f;
  dst[2] = src_uint8[2] / 255.f;
}

inline void float_to_uint8(unsigned char *dst, float src[3]) {
  uint8_t *dst_uint8 = (uint8_t *)dst;
  dst_uint8[0] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[0])));
  dst_uint8[1] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[1])));
  dst_uint8[2] = (uint8_t)(255.f * max(0.0f, min(1.0f, src[2])));
}

void Texture::generate_mips(int startLevel) {

  // make sure there's a valid texture
  if (startLevel >= mipmap.size()) {
    std::cerr << "Invalid start level";
  }

  // allocate sublevels
  int baseWidth = mipmap[startLevel].width;
  int baseHeight = mipmap[startLevel].height;
  int numSubLevels = (int)(log2f((float)max(baseWidth, baseHeight)));

  numSubLevels = min(numSubLevels, kMaxMipLevels - startLevel - 1);
  mipmap.resize(startLevel + numSubLevels + 1);

  int width = baseWidth;
  int height = baseHeight;
  for (int i = 1; i <= numSubLevels; i++) {

    MipLevel &level = mipmap[startLevel + i];

    // handle odd size texture by rounding down
    width = max(1, width / 2);
    //assert (width > 0);
    height = max(1, height / 2);
    //assert (height > 0);

    level.width = width;
    level.height = height;
    level.texels = vector<unsigned char>(3 * width * height);
  }

  // create mips
  int subLevels = numSubLevels - (startLevel + 1);
  for (int mipLevel = startLevel + 1; mipLevel < startLevel + subLevels + 1;
       mipLevel++) {

    MipLevel &prevLevel = mipmap[mipLevel - 1];
    MipLevel &currLevel = mipmap[mipLevel];

    int prevLevelPitch = prevLevel.width * 3; // 32 bit RGB
    int currLevelPitch = currLevel.width * 3; // 32 bit RGB

    unsigned char *prevLevelMem;
    unsigned char *currLevelMem;

    currLevelMem = (unsigned char *)&currLevel.texels[0];
    prevLevelMem = (unsigned char *)&prevLevel.texels[0];

    float wDecimal, wNorm, wWeight[3];
    int wSupport;
    float hDecimal, hNorm, hWeight[3];
    int hSupport;

    float result[3];
    float input[3];

    // conditional differentiates no rounding case from round down case
    if (prevLevel.width & 1) {
      wSupport = 3;
      wDecimal = 1.0f / (float)currLevel.width;
    } else {
      wSupport = 2;
      wDecimal = 0.0f;
    }

    // conditional differentiates no rounding case from round down case
    if (prevLevel.height & 1) {
      hSupport = 3;
      hDecimal = 1.0f / (float)currLevel.height;
    } else {
      hSupport = 2;
      hDecimal = 0.0f;
    }

    wNorm = 1.0f / (2.0f + wDecimal);
    hNorm = 1.0f / (2.0f + hDecimal);

    // case 1: reduction only in horizontal size (vertical size is 1)
    if (currLevel.height == prevLevel.height) {
      //assert (currLevel.height == 1);

      for (int i = 0; i < currLevel.width; i++) {
        wWeight[0] = wNorm * (1.0f - wDecimal * i);
        wWeight[1] = wNorm * 1.0f;
        wWeight[2] = wNorm * wDecimal * (i + 1);

        result[0] = result[1] = result[2] = 0.0f;

        for (int ii = 0; ii < wSupport; ii++) {
          uint8_to_float(input, prevLevelMem + 3 * (2 * i + ii));
          result[0] += wWeight[ii] * input[0];
          result[1] += wWeight[ii] * input[1];
          result[2] += wWeight[ii] * input[2];
        }

        // convert back to format of the texture
        float_to_uint8(currLevelMem + (3 * i), result);
      }

      // case 2: reduction only in vertical size (horizontal size is 1)
    } else if (currLevel.width == prevLevel.width) {
      //assert (currLevel.width == 1);

      for (int j = 0; j < currLevel.height; j++) {
        hWeight[0] = hNorm * (1.0f - hDecimal * j);
        hWeight[1] = hNorm;
        hWeight[2] = hNorm * hDecimal * (j + 1);

        result[0] = result[1] = result[2] = 0.0f;
        for (int jj = 0; jj < hSupport; jj++) {
          uint8_to_float(input, prevLevelMem + prevLevelPitch * (2 * j + jj));
          result[0] += hWeight[jj] * input[0];
          result[1] += hWeight[jj] * input[1];
          result[2] += hWeight[jj] * input[2];
        }

        // convert back to format of the texture
        float_to_uint8(currLevelMem + (currLevelPitch * j), result);
      }

      // case 3: reduction in both horizontal and vertical size
    } else {

      for (int j = 0; j < currLevel.height; j++) {
        hWeight[0] = hNorm * (1.0f - hDecimal * j);
        hWeight[1] = hNorm;
        hWeight[2] = hNorm * hDecimal * (j + 1);

        for (int i = 0; i < currLevel.width; i++) {
          wWeight[0] = wNorm * (1.0f - wDecimal * i);
          wWeight[1] = wNorm * 1.0f;
          wWeight[2] = wNorm * wDecimal * (i + 1);

          result[0] = result[1] = result[2] = 0.0f;

          // convolve source image with a trapezoidal filter.
          // in the case of no rounding this is just a box filter of width 2.
          // in the general case, the support region is 3x3.
          for (int jj = 0; jj < hSupport; jj++)
            for (int ii = 0; ii < wSupport; ii++) {
              float weight = hWeight[jj] * wWeight[ii];
              uint8_to_float(input, prevLevelMem +
                                        prevLevelPitch * (2 * j + jj) +
                                        3 * (2 * i + ii));
              result[0] += weight * input[0];
              result[1] += weight * input[1];
              result[2] += weight * input[2];
            }

          // convert back to format of the texture
          float_to_uint8(currLevelMem + currLevelPitch * j + 3 * i, result);
        }
      }
    }
  }
}

}
